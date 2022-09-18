PORTNAME=	clingo
DISTVERSIONPREFIX=	v
DISTVERSION=	5.6.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs
WWW=		https://potassco.org/clingo/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	re2c:devel/re2c

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_TUPLE=	potassco:clasp:4c708a7:potassco_clasp/clasp \
		catchorg:Catch2:62fd660:catch/third_party/catch \
		mpark:variant:23cb94f:variant/third_party/variant \
		TartanLlama:optional:c28fcf7:optional/third_party/optional \
		Tessil:hopscotch-map:4442316:hopscotch_map/third_party/hopscotch-map \
		Tessil:ordered-map:1619d52:ordered_map/third_party/ordered-map \
		Tessil:sparse-map:89d3053:sparse_map/third_party/sparse-map

CMAKE_OFF=	CLINGO_BUILD_WITH_PYTHON # broken, see https://github.com/potassco/clingo/issues/178
CMAKE_OFF+=	CLINGO_BUILD_WITH_LUA
CMAKE_TESTING_ON=	CLINGO_BUILD_TESTS

CONFLICTS_INSTALL=	clasp # only installs bin/clasp that is included in clingo

extra-test:
	@${ECHO} "Testing ${PORTNAME}: solving 15puzzle"
	@cd ${WRKSRC}/examples/clingo/15puzzle && \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/clingo encoding.lp instance1.lp -c consecutive=0

.include <bsd.port.mk>
