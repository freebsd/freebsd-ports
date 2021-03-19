# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$
# Check v4l_compat and v4l-utils slave ports

PORTNAME?=	libv4l
PORTVERSION=	1.20.0
DISTVERSIONPREFIX=	v4l-utils-
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Video4Linux library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

USES=		compiler:c11 tar:bzip2

USE_GITHUB=	yes
GH_ACCOUNT=	hselasky
GH_PROJECT=	v4l-utils

GH_TUPLE=	hselasky:webcamd:v5.10.6.0:webcamd \
		torvalds:linux:v5.10-rc6:linux

WEBCAMDDIR=	${WRKDIR}/webcamd-5.10.6.0
LINUXDIR=	${WRKDIR}/linux-*

.if ${PORTNAME} == v4l-utils || ${PORTNAME} == libv4l
LIB_DEPENDS+=	libargp.so:devel/argp-standalone \
		libudev.so:devel/libudev-devd
BUILD_DEPENDS+= gsed>0:textproc/gsed \
		v4l_compat>=${PORTVERSION}:multimedia/v4l_compat

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		autoreconf gettext-tools gmake iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	\
	--disable-qv4l2 \
	--disable-qvidcap \
	--disable-nls
BINARY_ALIAS=	sed=gsed
INSTALL_TARGET=	install-strip
.endif

.if ${PORTNAME} == v4l_compat
RUN_DEPENDS+=	evdev-proto>=5.3:devel/evdev-proto
.endif

.if ${PORTNAME} == v4l-utils
USES+=		perl5
BUILD_DEPENDS+=	libv4l>=${PORTVERSION}:multimedia/libv4l
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim \
		libv4l2.so:multimedia/libv4l
LDFLAGS+=	-lepoll-shim
CONFIGURE_ARGS+= \
	--enable-v4l-utils \
	--without-v4l2-compliance
.endif

.if ${PORTNAME} == libv4l
CONFIGURE_ENV+= \
	libudev_CFLAGS=" "
CONFIGURE_ARGS+= \
	--disable-v4l-utils \
	--enable-dyn-libv4l \
	--enable-libdvbv5
.endif

post-patch:
# Remove old FreeBSD include files (to be removed upstream)
	@${RM} -r ${WRKSRC}/contrib/freebsd/include/*
# Create symbolic link for Linux sources
	@(${RM} -r ${WEBCAMDDIR}/media_tree && ${LN} -s ${LINUXDIR} ${WEBCAMDDIR}/media_tree)
# Apply webcamd patches first
	@(cd ${WEBCAMDDIR}/patches && ${SH} ./do_patch.sh)
# Patch all source files
	@${FIND} ${WRKSRC} ${LINUXDIR}/include/uapi \
		-type f \( -iname "*.[ch]" -or -iname "*.cpp" -or -iname "cec-gen.pl" \) | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
			-e 's|__inline__|inline|g' \
			-e 's|__u8|uint8_t|g' \
			-e 's|__s8|int8_t|g' \
			-e 's|__le16|uint16_t|g' \
			-e 's|__be16|uint16_t|g' \
			-e 's|__u16|uint16_t|g' \
			-e 's|__s16|int16_t|g' \
			-e 's|__le32|uint32_t|g' \
			-e 's|__be32|uint32_t|g' \
			-e 's|__u32|uint32_t|g' \
			-e 's|__s32|int32_t|g' \
			-e 's|__le64|uint64_t|g' \
			-e 's|__be64|uint64_t|g' \
			-e 's|__u64|uint64_t|g' \
			-e 's|__s64|int64_t|g' \
			-e 's|uint16_t_to_cpu|letoh16|g' \
			-e 's|uint32_t_to_cpu|letoh32|g' \
			-e 's|uint64_t_to_cpu|letoh64|g' \
			-e 's|error_t|int|g' \
			-e 's|"gettext.h"|<stdio.h>|g' \
			-e 's|MSG_MORE|0|g' \
			-e 's|EBADR|EFAULT|g' \
			-e 's|ENONET|EHOSTDOWN|g' \
			-e 's|_IOC_READ|IOC_OUT|g' \
			-e 's|_IOC_WRITE|IOC_IN|g' \
			-e 's|_IOC_NONE|IOC_VOID|g' \
			-e 's|<endian.h>|<sys/endian.h>|g' \
			-e 's|<linux/compiler.h>|<sys/cdefs.h>|g' \
			-e 's|"compiler.h"|<sys/cdefs.h>|g' \
			-e 's|fallthrough;|;|g' \
			-e 's|<linux/errno.h>|<errno.h>|g' \
			-e 's|<linux/ioctl.h>|<sys/ioctl.h>|g' \
			-e '/^.*\<linux\/kernel.h\>.*/d' \
			-e 's|<linux/string.h>|<string.h>|g' \
			-e 's|<linux/sysmacros.h>|<sys/types.h>|g' \
			-e 's|<malloc.h>|<stdlib.h>|g' \
			-e 's|<sys/epoll.h>|<libepoll-shim/sys/epoll.h>|g' \
			-e 's|<sys/sysmacros.h>|<sys/types.h>|g' \
			-e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|g' \
			-e 's|__user||g'

.include <bsd.port.mk>
