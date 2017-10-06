# $FreeBSD$

PORTNAME=	PyAV
PORTVERSION=	0.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	eric@camachat.org
COMMENT=	Pythonic bindings for FFmpeg.

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		cython:lang/cython \
		ffmpeg:multimedia/ffmpeg
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	mikeboers
GH_PROJECT=	${DISTNAME}

USES=		cpe python pkgconfig
USE_PYTHON=	autoplist distutils

PYDISTUTILS_BUILD_TARGET=	build build_ext
PYDISTUTILS_BUILDARGS+=		saveopts

.include <bsd.port.mk>
