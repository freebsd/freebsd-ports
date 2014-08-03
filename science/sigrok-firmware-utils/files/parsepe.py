#!/usr/bin/env python3
##
## This file is part of the sigrok-util project.
##
## Copyright (C) 2012 Bert Vermeulen <bert@biot.com>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, see <http://www.gnu.org/licenses/>.
##

import sys
import os
from getopt import getopt
import struct


def parse(filename):
	f = open(filename, 'rb')
	if f.read(2) != b'MZ':
		raise Exception("MZ signature not found.")

	sections = []
	# long e_lfanew
	f.seek(0x3c)
	pe_ptr = struct.unpack("<L", f.read(4))[0]
	f.seek(pe_ptr)
	if f.read(4) != b'\x50\x45\x00\x00':
		raise Exception("PE signature not found.")
	# skip Machine
	f.seek(f.tell() + 2)
	sections.append(['header', 324, 0])
	num_sections = struct.unpack("<H", f.read(2))[0]
	# skip TimeDateStamp
	f.seek(f.tell() + 4)
	symboltable_address = struct.unpack("<L", f.read(4))[0]
	num_symbols = struct.unpack("<L", f.read(4))[0]
	optheader_size = struct.unpack("<H", f.read(2))[0]
	# skip past PE header and PE optional header
	f.seek(f.tell() + 2 + optheader_size)

	for i in range(num_sections):
		name = f.read(8).decode('ascii', errors='ignore').strip('\x00')
		# skip past Misc and VirtualAddress
		f.seek(f.tell() + 8)
		# SizeOfRawData
		size = struct.unpack("<L", f.read(4))[0]
		# PointerToRawData
		ptr = struct.unpack("<L", f.read(4))[0]
		# skip to next section header
		f.seek(f.tell() + 16)
		sections.append([name, size, ptr])

	symbols = []
	addr = symboltable_address
	stringtable_address = symboltable_address + num_symbols * 18
	for i in range(num_symbols):
		f.seek(addr)
		tmp = f.read(8)
		symaddr = struct.unpack("<L", f.read(4))[0]
		# skip SectionNumber and Type
		symtype = struct.unpack("B", f.read(1))[0]
		f.seek(f.tell() + 4)
		if tmp[:4] == b'\x00\x00\x00\x00':
			# symbol name is in the string table
			straddr = stringtable_address + struct.unpack("<l", tmp[4:])[0]
			f.seek(straddr)
			tmpname = f.read(64)
			name = tmpname[:tmpname.find(b'\x00')]
		else:
			name = tmp
		name = name.decode('ascii', errors='ignore').strip('\x00')
		# need IMAGE_SYM_CLASS_EXTERNAL
		if symtype == 0x02:
			size = 0
		else:
			size = None
		if i != 0 and symbols[-1][2] is not None and symaddr > symbols[-1][1]:
			symbols[-1][2] = symaddr - symbols[-1][1]
		symbols.append([name, symaddr, size])
		addr += 18

	f.close()

	return sections, symbols


def list_all(filename):
	sections, symbols = parse(filename)
	if sections:
		print("Sections:\n    Name         Size\t  Position")
		cnt = 0
		for name, size, address in sections:
			print("%-3d %-8s    %5d\t  0x%.8x" % (cnt, name, size, address))
			cnt += 1
	if symbols:
		print("\nSymbol table:\n   Address     Size    Symbol")
		for symbol, address, size in symbols:
			if size is not None:
				sizestr = "%5d" % size
			else:
				sizestr = "     "
			print("0x%.8x  %s    %-8s" % (address, sizestr, symbol))
		print()


def extract_symbol(filename, symbol):
	sections, symbols = parse(filename)
	if not symbols:
		return None
	data = None
	for symbolname, address, size in symbols:
		if symbolname == symbol:
			if size is None:
				raise Exception("symbol %s found, but has unknown size")
			f = open(filename, 'rb')
			f.seek(address)
			data = f.read(size)
			f.close()
			if len(data) != size:
				raise Exception("short file")
			break

	if data is None:
		raise Exception("symbol %s not found" % symbol)

	return data



def usage():
	print("usage: parsepe.py [-s <symbol>] <-l|-x> <filename>")
	print("  -l   list all sections and symbols in file")
	print("  -x   extract symbol from file (specify symbol name with -s)")
	sys.exit()


#
# main
#

if __name__ == '__main__':
	filename = symbol = mode = None
	opts, args = getopt(sys.argv[1:], 's:lx')
	for opt, arg in opts:
		if opt == '-s':
			symbol = arg
		elif opt == '-l':
			mode = 'list'
		elif opt == '-x':
			mode = 'extract'

	if len(args) != 1:
		usage()
	if mode is None and symbol is None:
		usage()

	try:
		filename = args[0]
		if mode == 'list':
			list_all(filename)
		elif mode == 'extract':
			if symbol is None:
				raise Exception("specify a symbol to extract")
			data = extract_symbol(filename, symbol)
			outfile = os.path.splitext(filename)[0] + symbol
			open(outfile, 'wb').write(data)
			print("saved %d bytes to %s" % (len(data), outfile))
		else:
			raise Exception("specify -l or -x")
	except Exception as e:
		print("Error: %s" % str(e))


