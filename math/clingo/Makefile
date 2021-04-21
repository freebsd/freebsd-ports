PORTNAME=	clingo
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	re2c:devel/re2c

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_TUPLE=	potassco:clasp:a8dfc0a:potassco_clasp/clasp \
		potassco:libpotassco:2f9fb7ca2c202f1b47643aa414054f2f4f9c1821:potassco_libpotassco/clasp/libpotassco

USE_LDCONFIG=	yes

CMAKE_OFF=	CLINGO_BUILD_WITH_PYTHON # broken, see https://github.com/potassco/clingo/issues/178
CMAKE_OFF+=	CLINGO_BUILD_WITH_LUA

CONFLICTS_INSTALL=	clasp # only installs bin/clasp that is included in clingo

do-test:
	${ECHO} "Testing ${PORTNAME}: solving 15puzzle"
	@cd ${WRKSRC}/examples/clingo/15puzzle && \
		${STAGEDIR}${PREFIX}/bin/clingo encoding.lp instance1.lp -c consecutive=0

.include <bsd.port.mk>
