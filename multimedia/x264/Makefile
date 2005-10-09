# New ports collection makefile for:	x264
# Date created:		2005-01-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x264
PORTVERSION=	0.0.20051004
CATEGORIES=	multimedia
MASTER_SITES=	http://downloads.videolan.org/pub/videolan/x264/snapshots/
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION:S/0.0.//}-2245

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Multimedia library and tool for encoding H.264/AVC video streams

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
SHLIB_VER=	1
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes

PLIST_FILES=	bin/x264 \
		include/x264.h \
		lib/libx264.a \
		lib/libx264.so \
		lib/libx264.so.${SHLIB_VER}

OPTIONS=	GPAC "Enable MPEG-4 Output" On \
		DEBUG "Enable Debugging" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off \
		X11_OUTPUT "Enable X11 Output" Off

CONFIGURE_ARGS+=	--extra-cflags="${CPPFLAGS} ${CFLAGS} -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
			--extra-ldflags="${LDFLAGS} -L${LOCALBASE}/lib -L${X11BASE}/lib"
#			--enable-pthread

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ENV+=	ARCH_X86="1"
.endif

.if ${ARCH}=="amd64"
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
MAKE_ENV+=	ARCH_X86_64="1"
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -funroll-loops -ffast-math
.endif

.if !defined(WITHOUT_GPAC)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libgpac_static.a:${PORTSDIR}/multimedia/gpac-libgpac
CONFIGURE_ARGS+=	--enable-mp4-output
.endif

.if defined(WITH_X11_OUTPUT)
CONFIGURE_ARGS+=	--enable-visualize
USE_XLIB=		yes
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x264 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/x264.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libx264.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libx264.so.${SHLIB_VER} ${PREFIX}/lib
	${LN} -sf libx264.so.${SHLIB_VER} ${PREFIX}/lib/libx264.so

.include <bsd.port.post.mk>
