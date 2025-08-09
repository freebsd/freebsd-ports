PORTNAME=	chemicalfun
DISTVERSION=	0.1.8
PORTREVISION=	3
CATEGORIES=	science # chemistry
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${PORTNAME}/get/${BB_COMMIT}${EXTRACT_SUFX}?dummy=/:src
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for working with chemical reactions and formulas
WWW=		https://bitbucket.org/gems4/chemicalfun/src/master/

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libfmt.so:devel/libfmt # due to SPDLOG_FMT_EXTERNAL
LIB_DEPENDS+=	libspdlog.so:devel/spdlog

USES=		cmake:testing compiler:c++17-lang eigen:3 localbase

BB_ACCOUNT=	gems4
BB_COMMIT=	46c628fef376

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${PORTNAME}-${BB_COMMIT}

CMAKE_ARGS=	-DFREEBSD_PREFIX=${PREFIX} -DFREEBSD_STAGEDIR=${STAGEDIR} \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	CHEMICALFUN_BUILD_TESTS # tests fail to compile, BitBucket offers no easy way to report this
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack to prevent test run

CXXFLAGS+=	-DSPDLOG_FMT_EXTERNAL # see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=258073#c3
LDFLAGS+=	-L${LOCALBASE}/lib -lfmt # due to SPDLOG_FMT_EXTERNAL

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	CHEMICALFUN_BUILD_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PREFIX=${PREFIX}
PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11

post-install-PYTHON-on:
	# remove wrong *.pyc, see related bug https://bitbucket.org/gems4/chemicalfun/issues/1/please-support-stagedir
	@${FIND} ${STAGEDIR} -name "*.pyc" -delete
	@${FIND} ${STAGEDIR} -name __pycache__ -delete
	# strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/chemicalfun/PyChemicalFun${PYTHON_TAG}.so

post-test:
	@${ECHO} "==> run C++ tests"
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} tests/test_main

post-test-PYTHON-on:
	@${ECHO} "==> run Python tests"
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
