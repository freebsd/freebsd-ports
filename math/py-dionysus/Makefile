PORTNAME=	dionysus
PORTVERSION=	2.2.3
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-topology-library

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computing persistent homology
WWW=		https://mrzv.org/software/dionysus2/ \
		https://github.com/mrzv/dionysus

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/adaptors.hpp:devel/boost-libs \
		pybind11>=2:devel/pybind11
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}intervaltree>=3.1.0:devel/py-intervaltree@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.4.0:devel/py-sortedcontainers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=3.9.4:math/py-matplotlib@${PY_FLAVOR}

USES=		cmake compiler:c++14-lang python
USE_PYTHON=	flavors pytest

CMAKE_OFF=	build_examples

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} MPLBACKEND=Agg PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

PLIST_FILES=	${PYTHON_SITELIBDIR}/dionysus/__init__.py \
		${PYTHON_SITELIBDIR}/dionysus/_dionysus${PYTHON_TAG}.so \
		${PYTHON_SITELIBDIR}/dionysus/plot.py \
		${PYTHON_SITELIBDIR}/dionysus/zigzag.py \
		${PYTHON_SITELIBDIR}/dionysus-${PORTVERSION}.dist-info/METADATA

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus
	cd ${BUILD_WRKSRC}/bindings/python && ${INSTALL_LIB} _dionysus${PYTHON_TAG}.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus
	cd ${WRKSRC}/bindings/python/dionysus && ${INSTALL_DATA} __init__.py plot.py zigzag.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus

post-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus-${PORTVERSION}.dist-info
	@${ECHO_CMD} "Metadata-Version: 2.1" > ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus-${PORTVERSION}.dist-info/METADATA
	@${ECHO_CMD} "Name: dionysus" >> ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus-${PORTVERSION}.dist-info/METADATA
	@${ECHO_CMD} "Version: ${PORTVERSION}" >> ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dionysus-${PORTVERSION}.dist-info/METADATA

# tests as of 2.2.3: 99 passed, 2 skipped in 34.09s

.include <bsd.port.mk>
