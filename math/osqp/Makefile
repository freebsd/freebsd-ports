PORTNAME=	osqp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Operator Splitting Quadratic Program solver for optimization problems
WWW=		https://osqp.org \
		https://github.com/osqp/osqp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	catch>0:devel/catch \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		cmake:testing python
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	osqp:qdldl:v0.1.8:q/lin_sys/direct/qdldl/qdldl_sources

CMAKE_ARGS=	-DFETCHCONTENT_SOURCE_DIR_QDLDL=${WRKSRC}/lin_sys/direct/qdldl/qdldl_sources

CMAKE_OFF=	OSQP_BUILD_DEMO_EXE OSQP_BUILD_UNITTESTS OSQP_CODEGEN
CMAKE_TESTING_ON=	OSQP_BUILD_UNITTESTS

# tests as of 1.0.0: 100% tests passed, 0 tests failed out of 3

.include <bsd.port.mk>
