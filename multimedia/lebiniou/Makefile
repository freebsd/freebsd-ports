PORTNAME=	lebiniou
DISTVERSIONPREFIX=	version-
DISTVERSION=	3.67.0
CATEGORIES=	multimedia graphics

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	User-friendly, powerful music visualization / VJing tool
WWW=		https://biniou.lenain.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libavutil.so.58:multimedia/ffmpeg6 \
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
		libfreetype.so:print/freetype2
RUN_DEPENDS=	v4l_compat>0:multimedia/v4l_compat \
		${LOCALBASE}/share/lebiniou/vue/index.html:multimedia/lebiniou-data

USES=		autoreconf gl gnome magick pkgconfig sdl
USE_GL=		glu

USE_GITLAB=	YES

USE_GNOME=	glib20
USE_SDL=	sdl2
USE_LDCONFIG=	YES

GNU_CONFIGURE=	YES
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
