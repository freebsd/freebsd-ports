# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer1-libav/Makefile,v 1.4 2013/01/15 21:43:45 kwm Exp $

PORTNAME=	gstreamer1-libav
PORTVERSION=	1.2.3
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in with many audio/video decoders/encoders

LICENSE=	GPLv2

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		orc>=0.4.16:${PORTSDIR}/devel/orc
LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc

USES=		compiler gmake pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	VERSION="1.0"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033 || ${ARCH} == ia64
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${COMPILER_TYPE} == "gcc"
CFLAGS+=	-fno-force-addr
.endif

post-patch:
	@${REINPLACE_CMD} 's/[[:<:]]ARCH[[:>:]]/LIBAV_ARCH/' \
		${WRKSRC}/gst-libs/ext/libav/Makefile \
		${WRKSRC}/gst-libs/ext/libav/common.mak \
		${WRKSRC}/gst-libs/ext/libav/configure \
		${WRKSRC}/gst-libs/ext/libav/libavcodec/Makefile \
		${WRKSRC}/gst-libs/ext/libav/library.mak
	@${REINPLACE_CMD} '/libgstlibav_la_LDFLAGS =/s/$$/ -Wl,-Bsymbolic/' \
		${WRKSRC}/ext/libav/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgstlibav.so

.include <bsd.port.post.mk>
