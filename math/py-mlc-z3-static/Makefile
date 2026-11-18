PORTNAME=	mlc-z3-static
DISTVERSION=	5.3.1.post1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mlc_z3_static-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Z3 headers, static library and CMake metadata for build systems
WWW=		https://github.com/mlc-ai/package \
		https://github.com/Z3Prover/z3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.11:devel/py-scikit-build-core@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++20-lang ninja python
USE_PYTHON=	autoplist pep517 pytest
USE_GITHUB=	nodefault
# Z3 source pinned by version.py; the build uses it instead of downloading it
GH_TUPLE=	Z3Prover:z3:ac9156f97cb44e56472e1c841f7a2beb1e976b24:z3

MAKE_ENV+=	CMAKE_BUILD_PARALLEL_LEVEL=${MAKE_JOBS_NUMBER} \
		MLC_Z3_STATIC_SOURCE_DIR=${WRKDIR}/z3-ac9156f97cb44e56472e1c841f7a2beb1e976b24

# DESTDIR must not reach the CMake installs run by the build: they would write
# outside of the staged wheel, leaving the wheel without the Z3 artifacts
PEP517_BUILD_CMD=	${SETENV} -u DESTDIR ${PYTHON_CMD} -m build --no-isolation --wheel ${PEP517_BUILD_CONFIG_SETTING}

TEST_ARGS=	--disable-plugin-autoload
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 5.3.1.post1: 12 passed in 1.40s

.include <bsd.port.mk>
