# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-ffmpeg/Makefile,v 1.14 2006/07/20 13:40:27 ahze Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.10.13
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-ffmpeg/:ffmpeg \
		http://libav.org/releases/:libav
PKGNAMESUFFIX=	-ffmpeg
DISTFILES=	gst-ffmpeg-${PORTVERSION}.tar.bz2:ffmpeg \
		libav-${LIBAV_VERSION}.tar.xz:libav

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in for manipulating MPEG video streams

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm
LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc

LIBAV_VERSION=	0.7.7
WRKSRC=		${WRKDIR}/gst-ffmpeg-${PORTVERSION}
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
FFMPEG_CONFIG=	--cc=${CC} \
		--enable-runtime-cpudetect \
		--enable-pic
LDFLAGS+=	-Wl,-Bsymbolic
CFLAGS+=	-fno-force-addr
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG}

PLIST_SUB=	VERSION="${GST_VERSION}"

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
GST_VERSION=${PORTVERSION:C/..$//}

# sse hardware vector support
.if defined(MACHINE_CPU) && (${MACHINE_CPU:Msse} == "sse" || ${MACHINE_CPU:Mamd64} == "amd64")
WITH_BUILTIN_VECTOR=	yes
.else
FFMPEG_CONFIG+=	--disable-sse
.endif

# mmx support
.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "" && ${MACHINE_CPU:Mamd64} == ""
FFMPEG_CONFIG+=	--disable-mmx
WITHOUT_BUILTIN_VECTOR=	yes
.endif

# builtin vector, requires mmx and sse
.if !defined(WITHOUT_BUILTIN_VECTOR) && defined(WITH_BUILTIN_VECTOR)
CFLAGS+=		-msse
.endif

CONFIGURE_ARGS+=	--with-ffmpeg-extra-configure="${FFMPEG_CONFIG}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033

BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin

.endif

post-patch:
	@${MV} ${WRKSRC}/gst-libs/ext/libav ${WRKSRC}/gst-libs/ext/libav.old
	@${MV} ${WRKDIR}/libav-${LIBAV_VERSION} ${WRKSRC}/gst-libs/ext/libav
	@${CP} ${WRKSRC}/gst-libs/ext/libav.old/config.* \
		${WRKSRC}/gst-libs/ext/libav/

.include <bsd.port.post.mk>
