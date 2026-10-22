PORTNAME=	pulp
DISTVERSION=	4.1.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LP modeler written in python
WWW=		https://github.com/coin-or/pulp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.4<2:devel/py-maturin@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orloge>=1.0.0:devel/py-orloge@${PY_FLAVOR} \
		cbc:math/cbc \
		glpsol:math/glpk
OPT_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cbcbox>0:math/py-cbcbox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}highspy>0:math/py-highspy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PySCIPOpt>0:math/py-PySCIPOpt@${PY_FLAVOR}
TEST_DEPENDS=	${OPT_DEPENDS}

USES=		cargo cpe python
CPE_VENDOR=	pulpproject
USE_PYTHON=	pep517 concurrent autoplist pytest

CARGO_CARGOTOML=	${WRKSRC}/pulp/rust/Cargo.toml
CARGO_CARGOLOCK=	${WRKSRC}/pulp/rust/Cargo.lock
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_CRATES=	equivalent-1.0.2 \
		hashbrown-0.16.1 \
		heck-0.5.0 \
		indexmap-2.13.0 \
		libc-0.2.182 \
		once_cell-1.21.3 \
		portable-atomic-1.13.1 \
		proc-macro2-1.0.106 \
		pyo3-0.29.0 \
		pyo3-build-config-0.29.0 \
		pyo3-ffi-0.29.0 \
		pyo3-macros-0.29.0 \
		pyo3-macros-backend-0.29.0 \
		quote-1.0.45 \
		syn-2.0.117 \
		target-lexicon-0.13.5 \
		unicode-ident-1.0.24

MAKE_ENV+=	CARGO_TARGET_DIR=${WRKDIR}/_cargo_target

PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/${PORTNAME:tl:C|[-_]+|_|g}-${DISTVERSION}*.whl

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/pulp
TEST_ARGS=	--disable-plugin-autoload \
		-rs

do-test:
	#@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "from pulp.tests.run_tests import pulpTestAll; pulpTestAll()" || true
	#@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
	#	${PYTHON_CMD} -m pytest --import-mode=importlib
	#@cd ${WRKDIR} && ${SETENV} ${TEST_ENV} PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
	#	${PYTHON_CMD} -m pytest --import-mode=importlib ${STAGEDIR}${PYTHON_SITELIBDIR}/pulp
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} \
		${PYTHON_CMD} -m pytest ${TEST_ARGS} --import-mode=importlib ${STAGEDIR}${PYTHON_SITELIBDIR}/pulp

# tests as of 4.1.0: 1 failed, 368 passed, 672 skipped, 3 warnings in 9.02s # skipped tests are due to missing yaposib, sascas, etc solver, for 1 test failure see https://github.com/coin-or/pulp/issues/959

.include <bsd.port.mk>
