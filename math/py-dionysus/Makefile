PORTNAME=	dionysus
PORTVERSION=	2.0.10
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-topology-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computing persistent homology
WWW=		https://mrzv.org/software/dionysus2/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/adaptors.hpp:devel/boost-libs

USES=		cmake compiler:c++14-lang python
USE_PYTHON=	flavors pytest # 1 test fails, see https://github.com/mrzv/dionysus/issues/64, another one loops forever

CMAKE_ARGS=	-DPython_EXECUTABLE:STRING=${PYTHON_CMD}
CMAKE_OFF=	build_examples

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

PLIST_FILES=	${PYTHON_SITELIBDIR}/dionysus/__init__.py \
		${PYTHON_SITELIBDIR}/dionysus/_dionysus${PYTHON_EXT_SUFFIX}.so \
		${PYTHON_SITELIBDIR}/dionysus/_version.py \
		${PYTHON_SITELIBDIR}/dionysus/plot.py

do-install:
	cd ${BUILD_WRKSRC}/bindings/python && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
