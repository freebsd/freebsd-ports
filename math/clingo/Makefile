PORTNAME=	clingo
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Grounder and solver for logic programs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	re2c:devel/re2c

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	potassco
GH_TUPLE=	potassco:clasp:da10954:potassco_clasp/clasp

USE_LDCONFIG=	yes

CMAKE_OFF=	CLINGO_BUILD_WITH_PYTHON # broken, see https://github.com/potassco/clingo/issues/178
CMAKE_OFF+=	CLINGO_BUILD_WITH_LUA

CONFLICTS_INSTALL=	clasp # only installs bin/clasp that is included in clingo

do-test:
	@${ECHO} "Testing ${PORTNAME}: solving 15puzzle"
	@cd ${WRKSRC}/examples/clingo/15puzzle && \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/clingo encoding.lp instance1.lp -c consecutive=0

.include <bsd.port.mk>
