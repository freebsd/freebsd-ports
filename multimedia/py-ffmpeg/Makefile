# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	1.2.4
PORTREVISION=	5
CATEGORIES=	multimedia python
MASTER_SITES=	GH LOCAL/dbn/${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
# Should not be setting DISTNAME, USE_GITHUB already sets a very nice and unique distname.
DISTNAME=	${PORTNAME}-android-${PORTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Python bindings for FFmpeg

LICENSE=	LGPL20 LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	cython:lang/cython
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

MAKE_ENV=	FFMPEG_LIBRARIES="SDL SDL_mixer" FFMPEG_LIBRARY_DIRS=${LOCALBASE}/lib \
		FFMPEG_INCLUDES=${LOCALBASE}/include/SDL FFMPEG_ROOT=${LOCALBASE}
GH_ACCOUNT=	tito
GH_PROJECT=	${PORTNAME}-android
GH_TAGNAME=	6636c3a
USE_GITHUB=	yes
USES=		python:2
USE_PYTHON=	distutils autoplist
USE_SDL=	mixer
WRKSRC_SUBDIR=	python

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/ffmpeg/_ffmpeg.so

.include <bsd.port.mk>
