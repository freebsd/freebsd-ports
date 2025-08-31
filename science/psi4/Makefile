PORTNAME=	psi4
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
PORTREVISION=	4
CATEGORIES=	science # quantum-chemistry
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source suite of ab initio quantum chemistry programs
WWW=		https://psicode.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gau2grid>0:math/py-gau2grid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}optking>0:science/py-optking@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcelemental>0:science/py-qcelemental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcengine>0:science/py-qcengine@${PY_FLAVOR}
BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${LOCALBASE}/include/pybind11/pybind11.h:devel/pybind11 \
		${PY_DEPENDS} \
		${PY_SETUPTOOLS} \
		libint2-psi4>0:science/libint2-psi4 # has to be this library
LIB_DEPENDS=	libgg.so:math/gau2grid \
		libxc.so:science/libxc
RUN_DEPENDS=	${PY_DEPENDS} \
		libint2-psi4>0:science/libint2-psi4
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		blaslapack:openblas cmake compiler:c++17-lang eigen:3 fortran localbase:ldflags python
USE_GITHUB=	yes

CMAKE_ARGS=	-DLibxc_DIR=${LOCALBASE} \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER} \
		-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DPYMOD_INSTALL_LIBDIR=${PYTHONPREFIX_SITELIBDIR:S|${PREFIX}/lib||}
CONFIGURE_ENV=	FREEBSD_PYTHON_VER=${PYTHON_VER}

LDFLAGS+=	-lexecinfo # for backtrace_symbols

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4/tests \
		PSIDATADIR=${STAGEDIR}${DATADIR} \
		PSIPATH=${STAGEDIR}${DATADIR}/basis
TEST_WRKSRC=	${WRKSRC}/tests/pytests

BINARY_ALIAS=	python=${PYTHON_CMD} # only for tests

OPTIONS_DEFINE=	NATIVE

NATIVE_CMAKE_BOOL=	ENABLE_XHOST

post-patch:
	# correct the default data dir
	@${REINPLACE_CMD} \
		-E 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/psi4/run_psi4.py

do-install: # project fails to install itself into a stage directory due to a convoluted cmake code structure (DESTDIR isn't handled correctly)
	# main
	cd ${BUILD_WRKSRC}/stage && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
	${FIND} ${STAGEDIR}${PREFIX} -name "*.pyc" -delete
	# samples
	cd ${WRKSRC} && ${COPYTREE_SHARE} samples ${STAGEDIR}${DATADIR}
	${FIND} ${STAGEDIR}${PREFIX} -name "example_psi4rc_file" -delete
	# delete empty directories
	${FIND} ${STAGEDIR} -type d -empty -delete
	# set executable flag
	${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/psi4
	# correct version number
	@${REINPLACE_CMD} -i '' -e "s|__version__ = 'undefined'|__version__ = '${DISTVERSION}'|" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4/metadata.py
	@${REINPLACE_CMD} -i '' -e "s|__version_long = 'undefined+11'|__version_long = '${DISTVERSION}'|" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4/metadata.py

	# psi4 sometimes fails to print its version: https://github.com/psi4/psi4/issues/2831

do-test:
	# 2 tests fail, see https://github.com/psi4/psi4/issues/3014
	# 1.9: many tests fail: https://github.com/psi4/psi4/issues/3099
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} pytest # tests can run without this target too, but this way tests output is more concise and it looks more appealing

.include <bsd.port.mk>
