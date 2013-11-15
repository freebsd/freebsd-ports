# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multimarkdown
PORTVERSION=	4.3.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://codeload.github.com/fletcher/MultiMarkdown-4/legacy.tar.gz/${MM4_COMMIT}?dummy=/:MM4 \
				https://codeload.github.com/fletcher/MMD-Support/legacy.tar.gz/${SUPPORT_COMMIT}?dummy=/:support \
				https://codeload.github.com/fletcher/human-markdown-reference/legacy.tar.gz/${CHEAT_COMMIT}?dummy=/:cheat \
				https://codeload.github.com/nddrylliog/greg/legacy.tar.gz/${GREG_COMMIT}?dummy=/:greg
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:MM4 \
				greg-${GREG_COMMIT}${EXTRACT_SUFX}:greg
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Extended Markdown processor with more features, written in C

LICENSE=	MIT

MM4_COMMIT=		42a07ab
SUPPORT_COMMIT=	685c95c
CHEAT_COMMIT=	c23d807
GREG_COMMIT=	3f11f56

WRKSRC=	${WRKDIR}/fletcher-MultiMarkdown-4-${MM4_COMMIT}

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	CHEAT_SHEET EXTRAS HELPERS
CHEAT_SHEET_DESC=	HTML-based cheat sheat
EXTRAS_DESC=	Extra scripts and XSLT support
HELPERS_DESC=	Helper scripts (conflicts with emulators/mtools)

CHEAT_SHEET_DISTFILES=	human-markdown-reference-${CHEAT_COMMIT}${EXTRACT_SUFX}:cheat
EXTRAS_DISTFILES=	MMD-Support-${SUPPORT_COMMIT}${EXTRACT_SUFX}:support

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHELPERS}
CONFLICTS_INSTALL=	mtools-*
.endif

post-extract:
	@${MV} ${WRKDIR}/nddrylliog-greg-${GREG_COMMIT}/* ${WRKSRC}/greg
.if ${PORT_OPTIONS:MCHEAT_SHEET}
	@${MV} ${WRKDIR}/fletcher-human-markdown-reference-${CHEAT_COMMIT}/* ${WRKSRC}/cheat-sheet
.endif
.if ${PORT_OPTIONS:MEXTRAS}
	@${MV} ${WRKDIR}/fletcher-MMD-Support-${SUPPORT_COMMIT}/* ${WRKSRC}/Support
.endif
	
post-patch:
	@${REINPLACE_CMD} -E "s/^(CFLAGS).+=/\1 \+=/" ${WRKSRC}/Makefile ${WRKSRC}/greg/Makefile
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/scripts/*
.if ${PORT_OPTIONS:MEXTRAS}
	@${REINPLACE_CMD} -E "s,^(xslt_path)=.*,\1=${DATADIR},; s,(xslt_path)/../,\1/," \
		${WRKSRC}/Support/bin/*
	@${REINPLACE_CMD} -e "s,/usr/local,${PREFIX},g" ${WRKSRC}/Support/bin/*
.endif

pre-install:
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC}/cheat-sheet -type f -exec ${CHMOD} ${SHAREMODE} {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/multimarkdown ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.if ${PORT_OPTIONS:MEXTRAS}
	${INSTALL_SCRIPT} ${WRKSRC}/Support/bin/* ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/XSLT
	${INSTALL_DATA} ${WRKSRC}/Support/XSLT/* ${STAGEDIR}${DATADIR}/XSLT
	@${MKDIR} ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_SCRIPT} ${WRKSRC}/Support/Utilities/* ${STAGEDIR}${DATADIR}/utilities
	${INSTALL_DATA} ${WRKSRC}/Support/README.md ${STAGEDIR}${DOCSDIR}/README-extras.md
.endif

.if ${PORT_OPTIONS:MCHEAT_SHEET}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/cheat-sheet
	cd ${WRKSRC} && ${FIND} cheat-sheet | ${CPIO} -pdmu --quiet ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
