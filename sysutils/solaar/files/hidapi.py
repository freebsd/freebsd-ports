# $FreeBSD$
# This is based on previous support for libhidapi which was dropped in
# upstream commit f5d2eba.
import ctypes as _C
from struct import pack as _pack

_native = _C.CDLL("libhidapi.so")

class _NativeDeviceInfo(_C.Structure):
	pass
_NativeDeviceInfo._fields_ = [
	('path', _C.c_char_p),
	('vendor_id', _C.c_ushort),
	('product_id', _C.c_ushort),
	('serial', _C.c_wchar_p),
	('release', _C.c_ushort),
	('manufacturer', _C.c_wchar_p),
	('product', _C.c_wchar_p),
	('usage_page', _C.c_ushort),
	('usage', _C.c_ushort),
	('interface', _C.c_int),
	('next_device', _C.POINTER(_NativeDeviceInfo))
]

from collections import namedtuple
DeviceInfo = namedtuple('DeviceInfo', [
	'path',
	'vendor_id',
	'product_id',
	'serial',
	'release',
	'manufacturer',
	'product',
	'interface',
	'driver',
])
del namedtuple

def _makeDeviceInfo(native_device_info):
	return DeviceInfo(
		path=native_device_info.path.decode('ascii'),
		vendor_id=hex(native_device_info.vendor_id)[2:].zfill(4),
		product_id=hex(native_device_info.product_id)[2:].zfill(4),
		serial=native_device_info.serial if native_device_info.serial else None,
		release=hex(native_device_info.release)[2:],
		manufacturer=native_device_info.manufacturer,
		product=native_device_info.product,
		interface=native_device_info.interface,
		driver=None)

_native.hid_init.argtypes = None
_native.hid_init.restype = _C.c_int

_native.hid_exit.argtypes = None
_native.hid_exit.restype = _C.c_int

_native.hid_enumerate.argtypes = [_C.c_ushort, _C.c_ushort]
_native.hid_enumerate.restype = _C.POINTER(_NativeDeviceInfo)

_native.hid_free_enumeration.argtypes = [_C.POINTER(_NativeDeviceInfo)]
_native.hid_free_enumeration.restype = None

_native.hid_open.argtypes = [_C.c_ushort, _C.c_ushort, _C.c_wchar_p]
_native.hid_open.restype = _C.c_void_p

_native.hid_open_path.argtypes = [_C.c_char_p]
_native.hid_open_path.restype = _C.c_void_p

_native.hid_close.argtypes = [_C.c_void_p]
_native.hid_close.restype = None

_native.hid_write.argtypes = [_C.c_void_p, _C.c_char_p, _C.c_size_t]
_native.hid_write.restype = _C.c_int

_native.hid_read.argtypes = [_C.c_void_p, _C.c_char_p, _C.c_size_t]
_native.hid_read.restype = _C.c_int

_native.hid_read_timeout.argtypes = [_C.c_void_p, _C.c_char_p, _C.c_size_t, _C.c_int]
_native.hid_read_timeout.restype = _C.c_int

_native.hid_set_nonblocking.argtypes = [_C.c_void_p, _C.c_int]
_native.hid_set_nonblocking.restype = _C.c_int

_native.hid_send_feature_report.argtypes = [_C.c_void_p, _C.c_char_p, _C.c_size_t]
_native.hid_send_feature_report.restype = _C.c_int

_native.hid_get_feature_report.argtypes = [_C.c_void_p, _C.c_char_p, _C.c_size_t]
_native.hid_get_feature_report.restype = _C.c_int

_native.hid_get_manufacturer_string.argtypes = [_C.c_void_p, _C.c_wchar_p, _C.c_size_t]
_native.hid_get_manufacturer_string.restype = _C.c_int

_native.hid_get_product_string.argtypes = [_C.c_void_p, _C.c_wchar_p, _C.c_size_t]
_native.hid_get_product_string.restype = _C.c_int

_native.hid_get_serial_number_string.argtypes = [_C.c_void_p, _C.c_wchar_p, _C.c_size_t]
_native.hid_get_serial_number_string.restype = _C.c_int

_native.hid_get_indexed_string.argtypes = [_C.c_void_p, _C.c_int, _C.c_wchar_p, _C.c_size_t]
_native.hid_get_indexed_string.restype = _C.c_int

_native.hid_error.argtypes = [_C.c_void_p]
_native.hid_error.restype = _C.c_wchar_p

def init():
	return _native.hid_init() == 0

def exit():
	return _native.hid_exit() == 0

def monitor_glib(callback, *device_filters):
	pass

def enumerate(vendor_id=None, product_id=None, interface_number=None, hid_driver=None):
	devices = _native.hid_enumerate(vendor_id, product_id)
	d = devices
	while d:
		if interface_number is None or interface_number == d.contents.interface:
			yield _makeDeviceInfo(d.contents)
		d = d.contents.next_device

	if devices:
		_native.hid_free_enumeration(devices)

def open(vendor_id, product_id, serial=None):
	return _native.hid_open(vendor_id, product_id, serial) or None

def open_path(device_path):
	if type(device_path) == str:
		device_path = device_path.encode('ascii')
	return _native.hid_open_path(device_path) or None

def close(device_handle):
	_native.hid_close(device_handle)

def write(device_handle, data):
	bytes_written = _native.hid_write(device_handle, _C.c_char_p(data), len(data))
	if bytes_written != len(data):
		raise IOError(_errno.EIO, 'written %d bytes out of expected %d' % (bytes_written, len(data)))

def read(device_handle, bytes_count, timeout_ms=-1):
	out_buffer = _C.create_string_buffer(b'\x00' * (bytes_count + 1))
	bytes_read = _native.hid_read_timeout(device_handle, out_buffer, bytes_count, timeout_ms)
	if bytes_read == -1:
		return None
	if bytes_read == 0:
		return b''
	return out_buffer[:bytes_read]

def send_feature_report(device_handle, data, report_number=None):
	if report_number is not None:
		data = _pack(b'!B', report_number) + data
	bytes_written = _native.hid_send_feature_report(device_handle, _C.c_char_p(data), len(data))
	return bytes_written > -1

def get_feature_report(device_handle, bytes_count, report_number=None):
	out_buffer = _C.create_string_buffer('\x00' * (bytes_count + 2))
	if report_number is not None:
		out_buffer[0] = _pack(b'!B', report_number)
	bytes_read = _native.hid_get_feature_report(device_handle, out_buffer, bytes_count)
	if bytes_read > -1:
		return out_buffer[:bytes_read]

def _read_wchar(func, device_handle, index=None):
	_BUFFER_SIZE = 64
	buf = _C.create_unicode_buffer('\x00' * _BUFFER_SIZE)
	if index is None:
		ok = func(device_handle, buf, _BUFFER_SIZE)
	else:
		ok = func(device_handle, index, buf, _BUFFER_SIZE)
	if ok == 0:
		return buf.value

def get_manufacturer(device_handle):
	return _read_wchar(_native.hid_get_manufacturer_string, device_handle)

def get_product(device_handle):
	return _read_wchar(_native.hid_get_product_string, device_handle)

def get_serial(device_handle):
	serial = _read_wchar(_native.hid_get_serial_number_string, device_handle)
	if serial is not None:
		return ''.join(hex(ord(c)) for c in serial)

def get_indexed_string(device_handle, index):
	return _read_wchar(_native.hid_get_indexed_string, device_handle, index)
