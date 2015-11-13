# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-libav
PORTVERSION=	1.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-libav/
DISTNAME=	gst-libav-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer plug-in with many audio/video decoders/encoders

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yasm:${PORTSDIR}/devel/yasm \
		orc>=0.4.16:${PORTSDIR}/devel/orc
LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

PORTSCOUT=	limitw:1,even

USES=		compiler:features gmake libtool pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libav

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv6"
CONFIGURE_ENV+=	ASFLAGS=-no-integrated-as
.endif

.if ${ARCH} == ia64
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
MAKE_ENV=	COMPILER_PATH=${LOCALBASE}/bin
.endif

.if ${COMPILER_TYPE} == clang && ${ARCH} == i386
CFLAGS+=	-mstack-alignment=16 -mstackrealign
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

.include <bsd.port.post.mk>
