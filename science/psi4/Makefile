PORTNAME=	psi4
DISTVERSION=	1.6.1.20221122
CATEGORIES=	science # quantum-chemistry
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source suite of ab initio quantum chemistry programs
WWW=		https://psicode.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gau2grid>0:math/py-gau2grid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcelemental>0:science/py-qcelemental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcengine>0:science/py-qcengine@${PY_FLAVOR}
BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		${LOCALBASE}/include/pybind11/pybind11.h:devel/pybind11 \
		${PY_DEPENDS} \
		libint2-psi4>0:science/libint2-psi4 # has to be this library
LIB_DEPENDS=	libgg.so:math/gau2grid \
		libxc.so:science/libxc
RUN_DEPENDS=	${PY_DEPENDS} \
		libint2-psi4>0:science/libint2-psi4

USES=		blaslapack:openblas cmake compiler:c++17-lang eigen:3 fortran localbase:ldflags python:3.8+

USE_GITHUB=	yes
GH_TAGNAME=	0889d6d34

CMAKE_ARGS=	-DLibxc_DIR=${LOCALBASE} \
		-DFREEBSD_PYTHON_VER=${PYTHON_VER} \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CONFIGURE_ENV=	FREEBSD_PYTHON_VER=${PYTHON_VER}

LDFLAGS+=	-lexecinfo # for backtrace_symbols

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4/tests \
		PSIDATADIR=${STAGEDIR}${DATADIR}

post-patch:
	# correct the default data dir
	@${REINPLACE_CMD} \
		-E 's|os.path.sep.join\(\[os.path.abspath\(os.path.dirname\(__file__\)\), "share", "psi4"\]\)|"${DATADIR}"|' \
		${WRKSRC}/psi4/run_psi4.py
	@${REINPLACE_CMD} \
		-E 's|from pathlib import Path|&; os.environ["PSIDATADIR"] = "${DATADIR}"|' \
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
	# move python module to a proper place
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${MV} ${STAGEDIR}${PREFIX}/lib/psi4 ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${RLN} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4 ${STAGEDIR}${PREFIX}/lib/psi4 # for the path-calculating logic in psi4/__init__.py
	# correct version number
	@${REINPLACE_CMD} -i '' -e "s|__version__ = 'undefined'|__version__ = '${DISTVERSION}'|" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4/metadata.py
	@${REINPLACE_CMD} -i '' -e "s|__version_long = 'undefined+11'|__version_long = '${DISTVERSION}'|" \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/psi4/metadata.py

do-test: # based on https://psicode.org/psi4manual/master/build_planning.html#faq-minutetests - most tests fail due to path mismatches
	@cd ${WRKSRC}/tests/isapt2 && ${SETENV} ${TEST_ENV} pytest

.include <bsd.port.mk>
