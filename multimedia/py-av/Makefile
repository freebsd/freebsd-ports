PORTNAME=	av
DISTVERSION=	19.0.1
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

USES=		python:3.12+ pkgconfig
USE_PYTHON=	autoplist concurrent cython pep517

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31200
IGNORE=	does not support Python below 3.12
.endif

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|^license = "BSD-3-Clause"|license = { text = "BSD-3-Clause" }|; s|78|63|g; \
		s|3.3.0|3.2.9|g' ${WRKSRC}/pyproject.toml

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/av/ -name '*.so' | ${XARGS} ${STRIP_CMD}

.include <bsd.port.post.mk>
