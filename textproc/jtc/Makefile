# $FreeBSD$

PORTNAME=	jtc
DISTVERSION=	1.76
CATEGORIES=	textproc

MAINTAINER=	vulcan@wired.sh
COMMENT=	CLI tool to extract, manipulate and transform JSON

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++14-lang
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	ldn-softdev

LDFLAGS+=	-lexecinfo -lpthread

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	"Release Notes.md" "User Guide.md" "Walk-path tutorial.md" \
		README.md

OPTIONS_DEFINE=	BG_CC BG_DTS BG_FLOW BG_MTS DOCS NO_DBG NO_DBG_PARSER

BG_CC_DESC=		Every call to a copy-constructor of Jnode class will reveal itself
BG_DTS_DESC=		Makes time-stamp display delta (since last debug message) instead of absolute stamp
BG_FLOW_DESC=		All debuggable function/method calls will display an entry and exit point
BG_MTS_DESC=		Display absolute time-stamps in the debug message
NO_DBG_DESC=		Disable all debug messages
NO_DBG_PARSER_DESC=	Disable debug messages coming from parsing JSON

BG_CC_CXXFLAGS=		-DBG_CC
BG_DTS_CXXFLAGS=	-DBG_dTS
BG_FLOW_CXXFLAGS=	-BG_FLOW
BG_MTS_CXXFLAGS=	-DBG_mTS -DBG_uTS
NO_DBG_CXXFLAGS=	-DNDEBUG
NO_DBG_PARSER_CXXFLAGS=	-DNDBG_PARSER

do-build:
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.cpp -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
