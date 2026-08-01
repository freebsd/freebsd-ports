PORTNAME=	pyqubo
DISTVERSION=	1.5.0
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Python DSL for constructing QUBOs from mathematical expressions
WWW=		https://pyqubo.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>=1.2.12:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dimod>=0.9.14:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-neal>=0.5.7:science/py-dwave-neal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15.0:devel/py-six@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}nbsphinx>=0.8.3:textproc/py-nbsphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0.11.1:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.36.2:devel/py-wheel@${PY_FLAVOR} \
		boost-libs>0:devel/boost-libs \
		cimod>0:math/cimod \
		cmake:devel/cmake-core \
		ninja:devel/ninja \
		pybind11>0:devel/pybind11 \
		robin-hood-hashing>0:devel/robin-hood-hashing
RUN_DEPENDS=	${PY_DEPENDS}

USES=		eigen:3 python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	recruit-communications

CXXFLAGS+=	-I${LOCALBASE}/include/cimod \
		-I${LOCALBASE}/include/eigen3

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of pyqubo: 46 passed

.include <bsd.port.mk>
