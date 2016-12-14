# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multimarkdown
PORTVERSION=	4.7
CATEGORIES=	textproc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C

LICENSE=	MIT GPLv2+
LICENSE_COMB=	dual

USE_GITHUB=	yes
GH_ACCOUNT=	fletcher:DEFAULT nddrylliog:greg
GH_PROJECT=	MultiMarkdown-4 greg:greg
GH_TAGNAME=	98ecf13:greg
GH_SUBDIR=	greg:greg

ALL_TARGET=	${PORTNAME}
USES=		gmake

OPTIONS_DEFINE=		CHEAT_SHEET EXTRAS HELPERS DOCS
CHEAT_SHEET_DESC=	HTML-based cheat sheat
EXTRAS_DESC=		Extra scripts and XSLT support
HELPERS_DESC=		Helper scripts (conflicts with emulators/mtools)

CHEAT_SHEET_GH_PROJECT=	human-markdown-reference:cheat
CHEAT_SHEET_GH_TAGNAME=	199dae8:cheat
CHEAT_SHEET_GH_SUBDIR=	cheat-sheet:cheat
EXTRAS_GH_PROJECT=	MMD-Support:support
EXTRAS_GH_TAGNAME=	685c95c:support
EXTRAS_GH_SUBDIR=	Support:support

HELPERS_CONFLICTS_INSTALL=	mtools-*

OPTIONS_SUB=	yes

post-patch:
	@${REINPLACE_CMD} -E "s/^(CFLAGS).+=/\1 \+=/" ${WRKSRC}/Makefile ${WRKSRC}/greg/Makefile
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/scripts/*
	@${REINPLACE_CMD} -E 's,(-include) (GLibFacade.h),\1 ${WRKSRC}/\2,' ${WRKSRC}/Makefile

post-patch-EXTRAS-on:
	@${REINPLACE_CMD} -E "s,^(xslt_path)=.*,\1=${DATADIR},; s,(xslt_path)/../,\1/," \
		${WRKSRC}/Support/bin/*
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/Support/bin/*


do-install:
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	${INSTALL_PROGRAM} ${WRKSRC}/multimarkdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-EXTRAS-on:
	${INSTALL_SCRIPT} ${WRKSRC}/Support/bin/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/XSLT
	${INSTALL_DATA} ${WRKSRC}/Support/XSLT/* ${STAGEDIR}${DATADIR}/XSLT
	@${MKDIR} ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_SCRIPT} ${WRKSRC}/Support/Utilities/* ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_DATA} ${WRKSRC}/Support/README.md ${STAGEDIR}${DOCSDIR}/README-extras.md

post-install-CHEAT_SHEET-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cheat-sheet
	(cd ${WRKSRC} && ${COPYTREE_SHARE} cheat-sheet ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
