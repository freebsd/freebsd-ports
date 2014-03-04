# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer1-libav/Makefile,v 1.4 2013/01/15 21:43:45 kwm Exp $

PORTNAME=	gstreamer1-libav
PORTVERSION=	1.2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in for manipulating MPEG video streams

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		orc>=0.4.16:${PORTSDIR}/devel/orc
LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc

USE_XZ=		yes
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USES=		compiler:features gmake pkgconfig
LIBAV_CONFIG=	--cc=${CC} \
		--enable-runtime-cpudetect \
		--enable-pic
LDFLAGS+=	-Wl,-Bsymbolic

PLIST_SUB=	VERSION="1.0"

# sse hardware vector support
.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
WITH_BUILTIN_VECTOR=	yes
.else
LIBAV_CONFIG+=	--disable-sse
.endif

# mmx support
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "" && ${MACHINE_CPU:Mamd64} == ""
LIBAV_CONFIG+=	--disable-mmx
WITHOUT_BUILTIN_VECTOR=	yes
.endif

# builtin vector, requires mmx and sse
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
CFLAGS+=		-msse
.endif

CONFIGURE_ARGS+=	--with-libav-extra-configure="${LIBAV_CONFIG}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${ARCH} == powerpc64
FFMPEG_CONFIG+=	--arch=ppc64
.endif
 
.if ${COMPILER_TYPE} == "gcc"
CFLAGS+=	-fno-force-addr
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgstlibav.so

.include <bsd.port.post.mk>
