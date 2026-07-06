PORTNAME=	sparsediffpy
DISTVERSION=	0.5.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for SparseDiffEngine algorithmic differentiation
WWW=		https://github.com/SparseDifferentiation/SparseDiffPy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ninja:devel/ninja \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libopenblas.so:math/openblas
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist

.include <bsd.port.mk>
