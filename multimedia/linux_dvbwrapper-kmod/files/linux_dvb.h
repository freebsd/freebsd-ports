/*
 * Extracted from <linux/dvb/frontend.h>, which is:
 *
 * Copyright (C) 2000 Marcus Metzler <marcus@convergence.de>
 *		    Ralph  Metzler <ralph@convergence.de>
 *		    Holger Waechtler <holger@convergence.de>
 *		    Andre Draszik <ad@convergence.de>
 *		    for convergence integrated media GmbH
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#ifndef __LINUX_DVB_H
#define __LINUX_DVB_H

#include <sys/types.h>

struct dtv_property {
	uint32_t cmd;
	uint32_t reserved[3];
	union {
		uint32_t data;
		struct {
			uint8_t data[32];
			uint32_t len;
			uint32_t reserved1[3];
			void *reserved2;
		} buffer;
	} u;
	int result;
} __attribute__ ((packed));

/* num of properties cannot exceed DTV_IOCTL_MAX_MSGS per ioctl */
#define DTV_IOCTL_MAX_MSGS 64

struct dtv_properties {
	uint32_t num;
	struct dtv_property *props;
};

#define FE_SET_PROPERTY		   _IOW('o', 82, struct dtv_properties)
/* 
 * This is broken on linux as well but they workaround it in the driver.
 * Since this is impossible to do on FreeBSD fix the header instead.
 * Detailed and discussion :
 * http://lists.freebsd.org/pipermail/freebsd-multimedia/2010-April/010958.html
 */
#define FE_GET_PROPERTY		   _IOW('o', 83, struct dtv_properties)

#endif /*__LINUX_DVB_H*/
