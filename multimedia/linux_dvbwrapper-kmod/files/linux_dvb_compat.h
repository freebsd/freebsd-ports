#ifndef __LINUX_DVB_COMPAT_H
#define __LINUX_DVB_COMPAT_H

#include <sys/types.h>

struct l_dtv_property {
	uint32_t cmd;
	uint32_t reserved[3];
	union {
		uint32_t data;
		struct {
			uint8_t data[32];
			uint32_t len;
			uint32_t reserved1[3];
			l_uintptr_t reserved2;
		} buffer;
	} u;
	l_int result;
} __attribute__ ((packed));

struct l_dtv_properties {
	uint32_t num;
	l_uintptr_t props;
};

#endif /*__LINUX_DVB_H*/
