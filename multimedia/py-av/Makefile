PORTNAME=	av
DISTVERSION=	17.0.0
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pythonic binding for FFmpeg
WWW=		https://docs.mikeboers.com/pyav/develop/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

USES=		python pkgconfig
USE_PYTHON=	autoplist concurrent cython pep517

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "BSD-3-Clause"|license = { text = "BSD-3-Clause" }|; s|77|63|g' \
		${WRKSRC}/pyproject.toml

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/av/ -name '*.so' | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
