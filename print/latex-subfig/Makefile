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

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${STY_CAPTION}:${PORTSDIR}/print/latex-caption
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${STY_CAPTION}:${PORTSDIR}/print/latex-caption

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL} MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR}
USE_GMAKE=	YES
ALL_TARGET=	sty

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
STY_CAPTION=	${LOCALBASE}/${TEXMFLOCAL}/tex/latex/caption/caption.sty
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	subfig.dtx subfig.ins subfig.sty subfig.cfg

DOC_FILES=	README test1.tex test2.tex test3.tex \
		test4.tex test5.tex test6.tex

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
