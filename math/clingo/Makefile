PORTNAME=	clingo
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.0
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	92d7f44f5e7fc468af5b91f8c00135cf52caa5c2.patch:-p1 # fixes https://github.com/potassco/clingo/issues/606, https://github.com/potassco/clingo/issues/612

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs
WWW=		https://potassco.org/clingo/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	re2c:devel/re2c

USES=		cmake:testing compiler:c++14-lang python:test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_TUPLE=	potassco:clasp:e51b9cf:potassco_clasp/clasp \
		catchorg:Catch2:914aeec:catch/third_party/catch \
		ckormanyos:wide-integer:c725651:wide_integer/third_party/wide-integer \
		mpark:variant:23cb94f:variant/third_party/variant \
		TartanLlama:optional:3a1209d:optional/third_party/optional \
		Tessil:hopscotch-map:75f0584:hopscotch_map/third_party/hopscotch-map \
		Tessil:ordered-map:46adc0e:ordered_map/third_party/ordered-map \
		Tessil:sparse-map:1bc4561:sparse_map/third_party/sparse-map

CMAKE_OFF=	CLINGO_BUILD_WITH_PYTHON # broken, see https://github.com/potassco/clingo/issues/178
CMAKE_OFF+=	CLINGO_BUILD_WITH_LUA
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	CLINGO_BUILD_TESTS

CONFLICTS_INSTALL=	clasp # only installs bin/clasp that is included in clingo

extra-test:
	@${ECHO} "Testing ${PORTNAME}: solving 15puzzle"
	@cd ${WRKSRC}/examples/clingo/15puzzle && \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/clingo encoding.lp instance1.lp -c consecutive=0

# tests as of 5.8.0: 100% tests passed, 0 tests failed out of 4

.include <bsd.port.mk>
