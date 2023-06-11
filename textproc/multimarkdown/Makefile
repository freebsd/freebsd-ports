PORTNAME=	multimarkdown
DISTVERSION=	6.7.0
CATEGORIES=	textproc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C
WWW=		https://www.fletcherpenney.net/multimarkdown/

LICENSE=	BSD3CLAUSE GPLv2+ MIT ZLIB
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake compiler:c11 localbase:ldflags
USE_GITHUB=	yes

GH_ACCOUNT=	fletcher
GH_PROJECT=	MultiMarkdown-6

PORTDOCS=	README.md

OPTIONS_DEFINE=	CHEAT_SHEET DOCS EXTRAS HELPERS
OPTIONS_SUB=	yes

CHEAT_SHEET_DESC=	HTML-based cheat sheat
EXTRAS_DESC=		Extra scripts and XSLT support
HELPERS_DESC=		Helper scripts (conflicts with emulators/mtools)

CHEAT_SHEET_GH_PROJECT=	MultiMarkdown-6-Syntax-Guide:cheat
CHEAT_SHEET_GH_SUBDIR=	cheat-sheet:cheat
CHEAT_SHEET_GH_TAGNAME=	2cf0881:cheat
EXTRAS_GH_PROJECT=	MMD-Support:support
EXTRAS_GH_SUBDIR=	Support:support
EXTRAS_GH_TAGNAME=	685c95c:support

HELPERS_CONFLICTS_INSTALL=	mtools-*

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/scripts/*

post-patch-CHEAT_SHEET-on:
.for f in .gitignore Makefile scripts source templates
	@${RM} -r ${WRKSRC}/cheat-sheet/${f}
.endfor

post-patch-EXTRAS-on:
	@${REINPLACE_CMD} -E "s,^(xslt_path)=.*,\1=${DATADIR},; s,(xslt_path)/../,\1/," \
		${WRKSRC}/Support/bin/*
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/Support/bin/*

do-install-CHEAT_SHEET-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cheat-sheet
	(cd ${WRKSRC} && ${COPYTREE_SHARE} cheat-sheet ${STAGEDIR}${DOCSDIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXTRAS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/Support/bin/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/XSLT
	${INSTALL_DATA} ${WRKSRC}/Support/XSLT/* ${STAGEDIR}${DATADIR}/XSLT
	@${MKDIR} ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_SCRIPT} ${WRKSRC}/Support/Utilities/* ${STAGEDIR}${DATADIR}/utilities
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Support/README.md ${STAGEDIR}${DOCSDIR}/README-extras.md

.include <bsd.port.mk>
