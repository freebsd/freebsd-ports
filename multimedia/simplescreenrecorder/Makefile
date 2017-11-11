# $FreeBSD$

PORTNAME=	simplescreenrecorder
DISTVERSION=	0.3.8-26
DISTVERSIONSUFFIX=	-g0f6eebf
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Screen video recorder

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libavformat.so:multimedia/ffmpeg

USES=		gmake localbase libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	MaartenBaert
GH_PROJECT=	ssr
USE_GL=		gl glu
USE_QT4=	corelib gui moc_build rcc_build uic_build linguisttools_build
USE_XORG=	x11 xext xfixes xi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-assert
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PULSEAUDIO JACK
OPTIONS_DEFAULT=		PULSEAUDIO
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
JACK_CONFIGURE_WITH=		jack
JACK_LIB_DEPENDS=		libjack.so:audio/jack

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|-ldl([". ])|-lc\1|g' \
		-e 's|-ldl$$|-lc|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
