PORTNAME=	lightgbm
DISTVERSION=	4.7.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gradient boosting framework that uses tree based learning algorithms
WWW=		https://lightgbm.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv6 armv7 i386 # Exception: Cannot install LightGBM in 32-bit Python, please use 64-bit Python instead

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}narwhals>=1.15:math/py-narwhals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.0.2:science/py-scikit-learn@${PY_FLAVOR}
BUILD_DEPENDS=	cmake:devel/cmake-core \
		gmake:devel/gmake \
		${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.11.0:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		eigen:3 python
USE_PYTHON=	pep517 autoplist

CXXFLAGS+=	-I${LOCALBASE}/include/eigen3

BINARY_ALIAS=	make=${GMAKE}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/lightgbm/lib/lib_lightgbm.so

.include <bsd.port.mk>
