PORTNAME=	lebiniou
DISTVERSIONPREFIX=	version-
DISTVERSION=	3.67.0
PORTREVISION=	1
CATEGORIES=	multimedia graphics

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	User-friendly, powerful music visualization / VJing tool
WWW=		https://biniou.lenain.info/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

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
RUN_DEPENDS=	${LOCALBASE}/share/lebiniou/vue/index.html:multimedia/lebiniou-data

USES=		autoreconf gl gnome magick pkgconfig sdl
USE_GL=		glu

USE_GITLAB=	YES

USE_GNOME=	glib20
USE_SDL=	sdl2
USE_LDCONFIG=	YES

GNU_CONFIGURE=	YES
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} == 1600020
BROKEN=	missing structs in V4L2, see D59203
.elif ${OPSYS} == FreeBSD && ${OSVERSION} < 1600021
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
RUN_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
.endif

.include <bsd.port.post.mk>
