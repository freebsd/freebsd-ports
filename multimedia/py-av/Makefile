PORTNAME=	av
PORTVERSION=	8.0.3
CATEGORIES=	multimedia python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Pythonic binding for FFmpeg

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

USES=		python:3.5+ pkgconfig
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
