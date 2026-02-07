PORTNAME=	pyqubo
DISTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DWave: Python DSL for constructing QUBOs from mathematical expressions
WWW=		https://pyqubo.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>=1.2.10:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dimod>=0.9.14:science/py-dimod@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dwave-neal>=0.5.7:science/py-dwave-neal@${PY_FLAVOR} \
		${PYNUMPY} \
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=2.1.9:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=4.5.1:devel/py-coverage@${PY_FLAVOR}

USES=		eigen:3 python
USE_PYTHON=	distutils cython autoplist unittest

USE_GITHUB=	yes
GH_ACCOUNT=	recruit-communications

CXXFLAGS+=	-I${LOCALBASE}/include/cimod \
		-I${LOCALBASE}/include/eigen3

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
