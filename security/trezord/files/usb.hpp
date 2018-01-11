/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 SatoshiLabs
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <libusb.h>

namespace trezord
{
namespace usb
{

static std::unique_ptr< utils::async_executor > usb_executor;

struct usb_device_info {
    char path[10];
    uint16_t vendor_id;
    uint16_t product_id;

    usb_device_info *next;
};

// Init/exit

void
init()
{
    libusb_init(NULL);
    usb_executor.reset(new utils::async_executor());
}

void
exit()
{
    libusb_exit(NULL);
    usb_executor.reset();
}

// Enumeration

usb_device_info *
enumerate(unsigned short vendor_id, unsigned short product_id)
{
    return usb_executor->await([=] {
            libusb_device **devs = NULL;
            libusb_device *dev = NULL;
            struct usb_device_info *root = NULL; /* return object */
            struct usb_device_info *cur_dev = NULL;
            int i = 0;

            libusb_get_device_list(NULL, &devs);
            while ((dev = devs[i++]) != NULL) {
                    struct libusb_device_descriptor desc;
                    libusb_get_device_descriptor(dev, &desc);
                    if ((vendor_id == 0 || vendor_id == desc.idVendor) && (product_id == 0 || product_id == desc.idProduct)) {
                            struct usb_device_info *tmp;
                            tmp = (struct usb_device_info *) calloc(1, sizeof(struct usb_device_info));
                            if (cur_dev) {
                                    cur_dev->next = tmp;
                            } else {
                                    root = tmp;
                            }
                            cur_dev = tmp;

                            cur_dev->next = NULL;
                            snprintf(cur_dev->path, sizeof(cur_dev->path), "%04x:%04x",
                                    libusb_get_bus_number(dev),
                                    libusb_get_device_address(dev));

                            cur_dev->vendor_id = desc.idVendor;
                            cur_dev->product_id = desc.idProduct;
                    }
            }
            libusb_free_device_list(devs, 1);
            return root;
        });
}

void
free_enumeration(usb_device_info *devs)
{
    return usb_executor->await([=] {
            struct usb_device_info *d = devs;
            while (d) {
                    struct usb_device_info *next = d->next;
                    free(d);
                    d = next;
            }
        });
}

// Open/close

libusb_device_handle *
open_path(char const *path)
{
    return usb_executor->await([=] {
            libusb_device **devs = NULL;
            libusb_device *dev = NULL;
            libusb_device_handle *handle = NULL;
            int i = 0;

            libusb_get_device_list(NULL, &devs);
            while ((dev = devs[i++]) != NULL) {
                    char devpath[10];
                    snprintf(devpath, sizeof(devpath), "%04x:%04x",
                            libusb_get_bus_number(dev),
                            libusb_get_device_address(dev));
                    if (strncmp(devpath, path, sizeof(devpath)) == 0) {
                            if (libusb_open(dev, &handle) == 0) {
#if !defined(__FreeBSD__) || __FreeBSD_version >= 1100000
                                    libusb_set_auto_detach_kernel_driver(handle, 1);
#endif
                                    if (libusb_claim_interface(handle, 0)) {
                                            libusb_close(handle);
                                            handle = NULL;
                                    }
                            }
                            break;
                    }
            }
            libusb_free_device_list(devs, 1);
            return handle;
        });
}

void
close(libusb_device_handle *device)
{
    return usb_executor->await([=] {
            libusb_release_interface(device, 0);
            libusb_close(device);
        });
}

// Communication

int
write(libusb_device_handle *device, unsigned char *data, size_t length)
{
    return usb_executor->await([=] {
            int xfer = -1;
            libusb_interrupt_transfer(device, 0x01, data, length, &xfer, 0);
            return xfer;
        });
}

int
read(libusb_device_handle *device, unsigned char *data, size_t length)
{
    return usb_executor->await([=] {
            int xfer = -1;
            libusb_interrupt_transfer(device, 0x81, data, length, &xfer, 0);
            return xfer;
        });
}

}
}
