# $FreeBSD$

.if ${MACHINE_ARCH} == "amd64"
SFX= 32
CFLAGS+=-DCOMPAT_FREEBSD32 -DCOMPAT_LINUX32
.endif

CWARNFLAGS+=-Wno-missing-prototypes

KMOD=	linux_dvbwrapper
SRCS=	linux_dvbwrapper.c

.include <bsd.kmod.mk>
