PORTNAME=	av
DISTVERSION=	13.0.0
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pythonic binding for FFmpeg
WWW=		https://docs.mikeboers.com/pyav/develop/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

USES=		python pkgconfig
USE_PYTHON=	autoplist concurrent cython distutils

CFLAGS+=	-Wno-error=incompatible-function-pointer-types

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/av/ -name '*.so' | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
