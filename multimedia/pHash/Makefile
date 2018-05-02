# Created by: Naram Qashat <cyberbotx@cyberbotx.com>
# $FreeBSD$

PORTNAME=	pHash
PORTVERSION=	0.9.6
PORTREVISION=	9
CATEGORIES=	multimedia devel
MASTER_SITES=	http://phash.org/releases/ \
		http://www.cyberbotx.com/pHash/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Open source perceptual hash library

LICENSE=	GPLv3+

USES=		gmake libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PTHREAD_LIBS="-lpthread"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG FFTW JPEG OPENMP PNG
OPTIONS_MULTI=	HASHING
OPTIONS_MULTI_HASHING=	AUDIO IMAGE VIDEO
OPTIONS_DEFAULT=	FFTW JPEG PNG AUDIO IMAGE VIDEO
AUDIO_DESC=	Enable audio hashing
IMAGE_DESC=	Enable image hashing
VIDEO_DESC=	Enable video hashing

DEBUG_CONFIGURE_ENABLE=	debug

FFTW_CONFIGURE_WITH=	fftw
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3

JPEG_CONFIGURE_WITH=	libjpeg
JPEG_USES=		jpeg

OPENMP_CONFIGURE_ENABLE=openmp
OPENMP_USES=		compiler:openmp

PNG_CONFIGURE_WITH=	libpng
PNG_LIB_DEPENDS=	libpng.so:graphics/png

AUDIO_CONFIGURE_ENABLE=	audio-hash
AUDIO_LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
			libsamplerate.so:audio/libsamplerate \
			libmpg123.so:audio/mpg123

IMAGE_CONFIGURE_ENABLE=	image-hash
IMAGE_BUILD_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg
IMAGE_RUN_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg

VIDEO_CONFIGURE_ENABLE=	video-hash
VIDEO_BUILD_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg
VIDEO_RUN_DEPENDS=	${LOCALBASE}/include/CImg.h:graphics/cimg
VIDEO_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

post-patch:
# Avoid USES=autoreconf while keeping configure.ac patch for reference
	@${TOUCH} -r ${WRKSRC}/aclocal.m4 ${WRKSRC}/configure.ac

.include <bsd.port.mk>
