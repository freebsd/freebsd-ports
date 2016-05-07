# Created by: Andrew Thompson <thompsa@FreeBSD.org>
# $FreeBSD$
# Check v4l_compat and v4l-utils slave ports

PORTNAME?=	libv4l
PORTVERSION=	1.6.3
PORTREVISION?=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/v4l-utils/:master \
		LOCAL/kwm:local
DISTFILES+=	v4l-utils-${PORTVERSION}.tar.bz2:master \
		linux-3.16.7-dvb-headers.tar.xz:local

MAINTAINER=	multimedia@FreeBSD.org
COMMENT?=	Video4Linux library

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIBV4L_SLAVE?=	no

USES=		tar:bzip2
WRKSRC=		${WRKDIR}/v4l-utils-${PORTVERSION}

.if ${LIBV4L_SLAVE} != compat
BUILD_DEPENDS+=	v4l_compat>=${PORTVERSION}:multimedia/v4l_compat

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		gmake iconv jpeg libtool pathfix pkgconfig
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-libdvbv5 \
		--disable-qv4l2 \
		--without-libudev
INSTALL_TARGET=	install-strip

. if ${LIBV4L_SLAVE} == utils
BUILD_DEPENDS+=	libv4l>=${PORTVERSION}:multimedia/libv4l
LIB_DEPENDS+=	libargp.so:devel/argp-standalone \
		libv4l2.so:multimedia/libv4l
# Disabling building libv4l in the utils slave is too much hackery
# Lets wait for subpackages
CONFIGURE_ARGS+=--enable-v4l-utils
. else
CONFIGURE_ARGS+=--disable-v4l-utils --enable-libv4l
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-configure
. endif
.endif

HEADER_PATCHES=	extra-linux_dvb_ca.h \
		extra-linux_dvb_osd.h \
		patch-include_linux_dvb_frontend.h \
		patch-include_linux_dvb_video.h

post-patch:
	@${REINPLACE_CMD} -e 's|$$libdir/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/configure
# fix weird types, except a few headers which have compat code for these types.
	@${FIND} ${WRKDIR} -type f \( -iname "*.h" ! -iname "input.h" ! -iname "videodev2.h" \) | \
		${XARGS} -n 10 ${REINPLACE_CMD} \
		-e 's|linux/types.h|sys/types.h|g; s|__user||g; \
		s|__u8|uint8_t|g; s|__s8|int8_t|g; \
		s|__u16|uint16_t|g; s|__s16|int16_t|g; \
		s|__u32|uint32_t|g; s|__s32|int32_t|g; \
		s|__u64|uint64_t|g; s|__s64|int64_t|g'
.if ${LIBV4L_SLAVE} == compat
.for patch in ${HEADER_PATCHES}
	@cd ${WRKDIR}/linux && ${PATCH} -p2 < ${FILESDIR}/${patch}
.endfor
.endif

.include <bsd.port.mk>
