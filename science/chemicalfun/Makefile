PORTNAME=	chemicalfun
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.13
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for working with chemical reactions and formulas
WWW=		https://github.com/thermohub/chemicalfun

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
LIB_DEPENDS=	libfmt.so:devel/libfmt # due to SPDLOG_FMT_EXTERNAL
LIB_DEPENDS+=	libspdlog.so:devel/spdlog

USES=		cmake:testing compiler:c++20-lang eigen:3 localbase

USE_GITHUB=	yes
GH_ACCOUNT=	thermohub

CMAKE_TESTING_ON=	CHEMICALFUN_BUILD_TESTS # tests fail to compile, BitBucket offers no easy way to report this
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack to prevent test run

LDFLAGS+=		-L${LOCALBASE}/lib -lfmt # due to SPDLOG_FMT_EXTERNAL

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	PYTHON
OPTIONS_SUB=		yes

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	CHEMICALFUN_BUILD_PYTHON
PYTHON_CMAKE_ON=	-DFREEBSD_PREFIX=${PREFIX}
PYTHON_BUILD_DEPENDS=	pybind11>0:devel/pybind11

TEST_ENV=	LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib:${STAGEDIR}${LOCALBASE}/lib

post-test:
	@${ECHO} "==> run C++ tests"
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} tests/test_main

post-test-PYTHON-on:
	@${ECHO} "==> run Python tests"
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
