# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-ffmpeg/Makefile,v 1.14 2006/07/20 13:40:27 ahze Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.10.13
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-ffmpeg/:ffmpeg \
		http://libav.org/releases/:libav
PKGNAMESUFFIX=	-ffmpeg
DISTFILES=	gst-ffmpeg-${PORTVERSION}.tar.bz2:ffmpeg

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in for manipulating MPEG video streams

LICENSE=	GPLv2

NOT_FOR_ARCHS=		aarch64
NOT_FOR_ARCHS_REASON=	invokes x86 asm

LIB_DEPENDS=	liborc-0.4.so:devel/orc

PORTSCOUT=	limit:0\.10\..*

LIBAV_VERSION=	0.7.7
WRKSRC=		${WRKDIR}/gst-ffmpeg-${PORTVERSION}
USES=		compiler:features gmake libtool pkgconfig
USE_LDCONFIG=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=	FFMPEG
FFMPEG_DESC?=	Use system ffmpeg instead of internal libav

FFMPEG_LIB_DEPENDS=libavcodec0.so:multimedia/ffmpeg0
FFMPEG_CONFIGURE_WITH=system-ffmpeg
FFMPEG_VARS_OFF=NOPRECIOUSMAKEVARS=yes # ARCH

FFMPEG_DISTFILES_OFF=libav-${LIBAV_VERSION}.tar.xz:libav
FFMPEG_BUILD_DEPENDS_OFF=yasm:devel/yasm
FFMPEG_LDFLAGS_OFF=-Wl,-Bsymbolic
FFMPEG_CONFIGURE_OFF=--with-ffmpeg-extra-configure="${FFMPEG_CONFIG}"
FFMPEG_CONFIG=	--cc=${CC} \
		--enable-runtime-cpudetect \
		--enable-pic

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
FFMPEG_CFLAGS_OFF+=-msse
.endif

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MFFMPEG}

.if ${ARCH} == powerpc64
FFMPEG_CONFIG+=	--arch=ppc64
.endif

.if ${COMPILER_TYPE} == "gcc"
CFLAGS+=	-fno-force-addr
.endif

post-extract:
	@${MV} ${WRKSRC}/gst-libs/ext/libav ${WRKSRC}/gst-libs/ext/libav.old
	@${MV} ${WRKDIR}/libav-${LIBAV_VERSION} ${WRKSRC}/gst-libs/ext/libav
	@${CP} ${WRKSRC}/gst-libs/ext/libav.old/config.* \
		${WRKSRC}/gst-libs/ext/libav/
.endif # FFMPEG

post-patch:
	@${REINPLACE_CMD} -Ee '/sleep 15/d; /PKG_CONFIG/\
		s/lib(av(format|codec|util)|postproc|swscale)/&0/g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
