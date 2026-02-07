PORTNAME=	clingo
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7.1
CATEGORIES=	math

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
GH_TUPLE=	potassco:clasp:3f3db1e:potassco_clasp/clasp \
		catchorg:Catch2:3f0283d:catch/third_party/catch \
		ckormanyos:wide-integer:4c9711b:wide_integer/third_party/wide-integer \
		mpark:variant:23cb94f:variant/third_party/variant \
		TartanLlama:optional:3a1209d:optional/third_party/optional \
		Tessil:hopscotch-map:d35aa8c:hopscotch_map/third_party/hopscotch-map \
		Tessil:ordered-map:0557eb5:ordered_map/third_party/ordered-map \
		Tessil:sparse-map:7ab2fa0:sparse_map/third_party/sparse-map

CMAKE_OFF=	CLINGO_BUILD_WITH_PYTHON # broken, see https://github.com/potassco/clingo/issues/178
CMAKE_OFF+=	CLINGO_BUILD_WITH_LUA
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_TESTING_ON=	CLINGO_BUILD_TESTS

CONFLICTS_INSTALL=	clasp # only installs bin/clasp that is included in clingo

extra-test:
	@${ECHO} "Testing ${PORTNAME}: solving 15puzzle"
	@cd ${WRKSRC}/examples/clingo/15puzzle && \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/clingo encoding.lp instance1.lp -c consecutive=0

.include <bsd.port.mk>
