# New ports collection makefile for:	latex-subfig
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-subfig
PORTVERSION=	1.1.20040112
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www-2.cs.cmu.edu/afs/cs/usr/sdc/www/latex/
DISTNAME=	subfig.11

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package that supports small "sub" figures/tables

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
BUILD_DEPENDS+=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
BUILD_DEPENDS+=	${STY_CAPTION}:${PORTSDIR}/print/latex-caption
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}

USE_GMAKE=	YES
ALL_TARGET=	sty
TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
STY_CAPTION=	${LOCALBASE}/${TEXMFLOCAL}/tex/latex/caption/caption.sty
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	subfig.dtx
CLASS_FILES+=	subfig.ins
CLASS_FILES+=	subfig.sty
CLASS_FILES+=	subfig.cfg

DOC_FILES=	README
DOC_FILES+=	test1.tex
DOC_FILES+=	test2.tex
DOC_FILES+=	test3.tex
DOC_FILES+=	test4.tex
DOC_FILES+=	test5.tex
DOC_FILES+=	test6.tex

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	@${MKTEXLSR}

.include <bsd.port.mk>
