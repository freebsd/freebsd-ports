# New ports collection makefile for:	latex-bytefield
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-bytefield
PORTVERSION=	1.2.20050731
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/bytefield
DISTFILES=	bytefield.dtx bytefield.ins ${PORTDOCS}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package that utilization diagram of data fields

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

PLIST_SUB=	TEXMFDIR=${TEXMFDIR} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR}

TEXMFDIR=	share/texmf
TEXMFDIR_LSR=	${LOCALBASE}/${TEXMFDIR}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
TEX_BIN=	${LOCALBASE}/bin/etex
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	bytefield.dtx bytefield.sty bytefield.ins
PORTDOCS=	README bytefield.pdf example.pdf example.tex

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${DISTFILES} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${TEX_BIN} bytefield.ins

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR} ${TEXMFDIR}

.include <bsd.port.mk>
