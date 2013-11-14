# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multimarkdown
PORTVERSION=	4.3.2
CATEGORIES=	textproc
MASTER_SITES=	#none
DISTFILES=		#none

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C

LICENSE=	MIT

GITHUB_CREATOR=	fletcher
GIT_PROJECT_NAME=	MultiMarkdown-4
GIT_SUBMODULES=	yes

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	CHEAT_SHEET EXTRAS HELPERS
CHEAT_SHEET_DESC=	HTML-based cheat sheat
EXTRAS_DESC=	Extra scripts and XSLT support
HELPERS_DESC=	Helper scripts (conflicts with emulators/mtools)

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHELPERS}
CONFLICTS_INSTALL=	mtools-*
.endif

post-patch:
	@${REINPLACE_CMD} -E "s/^(CFLAGS).+=/\1 \+=/" ${WRKSRC}/Makefile ${WRKSRC}/greg/Makefile
	@${REINPLACE_CMD} -E "s,^(xslt_path)=.*,\1=${DATADIR},; s,(xslt_path)/../,\1/," \
		${WRKSRC}/Support/bin/*
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/Support/bin/* ${WRKSRC}/scripts/*

pre-install:
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC}/cheat-sheet -type f -not -path '*/.git' -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/multimarkdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/Support/bin/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/XSLT
	${INSTALL_DATA} ${WRKSRC}/Support/XSLT/* ${STAGEDIR}${DATADIR}/XSLT
	@${MKDIR} ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_SCRIPT} ${WRKSRC}/Support/Utilities/* ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_DATA} ${WRKSRC}/Support/README.md ${STAGEDIR}${DOCSDIR}/README-extras.md

	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cheat-sheet
	cd ${WRKSRC} && ${FIND} cheat-sheet -not -path '*/.git*' | \
		${CPIO} -pdmu --quiet ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/bsd.git-clone.mk"
.include <bsd.port.mk>
