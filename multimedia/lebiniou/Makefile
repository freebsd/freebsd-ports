PORTNAME=	lebiniou
DISTVERSION=	3.66.0
PORTREVISION=	6
CATEGORIES=	multimedia graphics

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	User-friendly, powerful music visualization / VJing tool
WWW=		https://biniou.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libcaca.so:graphics/libcaca \
		libfftw3.so:math/fftw3 \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		liborcania.so:devel/orcania \
		libyder.so:devel/yder \
		libulfius.so:www/ulfius \
		libjansson.so:devel/jansson \
		liblo.so:audio/liblo \
		libasound.so:audio/alsa-lib \
		libpulse.so:audio/pulseaudio \
		libsndio.so:audio/sndio \
		libsndfile.so:audio/libsndfile \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	v4l_compat>0:multimedia/v4l_compat \
		${LOCALBASE}/share/lebiniou/vue/index.html:multimedia/lebiniou-data

USES=		autoreconf gnome magick:6 sdl

USE_GNOME=	glib20
USE_SDL=	sdl2
USE_LDCONFIG=	YES
USE_GITLAB=	YES
GL_ACCOUNT=	lebiniou
GL_TAGNAME=	2049ce3d9ee5f860fb6a5d516c4af797f4669b58

GNU_CONFIGURE=	YES
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
