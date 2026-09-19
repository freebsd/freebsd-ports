PORTNAME=	xgboost
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.1
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable, Portable and Distributed Gradient Boosting (GBDT, GBRT, GBM)
WWW=		https://xgboost.ai/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_armv7=	compilation fails due to type conversion issues, like on i386, but the upstream says that they don't support 32-bit architectures
BROKEN_i386=	compilation fails, see https://github.com/dmlc/xgboost/issues/10002

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.11.0:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libdmlc.so:devel/dmlc-core
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS_dask=	\
		${PYTHON_PKGNAMEPREFIX}dask>0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distributed>0:devel/py-distributed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}
RUN_DEPENDS_plotting=	\
		${PYTHON_PKGNAMEPREFIX}graphviz>0:graphics/py-graphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.1.0:math/py-matplotlib@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pandas>=1.2:math/py-pandas@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR}
RUN_DEPENDS+=	${RUN_DEPENDS_dask}
RUN_DEPENDS+=	${RUN_DEPENDS_plotting}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}loky>0:devel/py-loky@${PY_FLAVOR}

USES=		compiler:c++17-lang python:3.12+ localbase:ldflags
USE_PYTHON=	pep517 autoplist pytest
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dmlc

WRKSRC_SUBDIR=	python-package
LDFLAGS+=	-lexecinfo \
		-ldmlc

PYDISTUTILS_INSTALLARGS=	--use-system-libxgboost # this is ignored so that setup.py has to be patched, see https://github.com/dmlc/xgboost/issues/6879

TEST_ENV=	${MAKE_ENV} \
		LD_LIBRARY_PATH=/lib \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		--deselect=python/test_tracker.py::test_rank_assignment \
		--deselect=python/test_updaters.py::TestTreeMethod::test_approx
TEST_WRKSRC=	${WRKSRC}/../tests/python

do-test:
	@${MKDIR} ${WRKDIR}/.bin
	@${LN} -sf ${PYTHON_CMD} ${WRKDIR}/.bin/python
	cd ${WRKSRC}/.. && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c 'import ctypes, pytest, sys; raise SystemExit(pytest.main(sys.argv[1:] + ["--ignore=tests/python/test_with_arrow.py", "tests/python"]))' ${TEST_ARGS}

post-install:
	@${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/xgboost/lib/libxgboost.so

.include <bsd.port.mk>
