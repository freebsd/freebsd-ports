# New ports collection makefile for:	latex-pgf
# Date created:		24 Jan 2004
# Whom:			hrs@FreeBSD.org
#
# $FreeBSD$

PORTNAME=	latex-pgf
PORTVERSION=	0.50
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	latex-beamer
DISTNAME=	${PORTNAME:S/^latex-//}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A LaTeX package for TeX Portable Graphic Format

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_BUILD=	YES
PLIST_SUB=	TEXMF=${TEXMF} MKTEXLSR=${MKTEXLSR}
PLIST_SUB+=	CLASSDIR=${CLASSDIR}

TEXMF=		share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMF}/tex/latex/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}/${PORTNAME:S/^latex-//}

CLASS_FILES=	pgf.sty
CLASS_FILES+=	pgfarrows.sty
CLASS_FILES+=	pgfautomata.sty
CLASS_FILES+=	pgfheaps.sty
CLASS_FILES+=	pgfnodes.sty
CLASS_FILES+=	pgfshade.sty
CLASS_FILES+=	xxcolor.sty

DOC_FILES=	AUTHORS
DOC_FILES+=	ChangeLog
DOC_FILES+=	FILES
DOC_FILES+=	INSTALL
DOC_FILES+=	README
DOC_FILES+=	TODO
DOC_FILES+=	apple.jpg
DOC_FILES+=	apple.mask.jpg
DOC_FILES+=	pgfuserguide.pdf
DOC_FILES+=	pgfuserguide.tex
DOC_FILES+=	tu-logo.25.eps
DOC_FILES+=	tu-logo.25.jpg
DOC_FILES+=	tu-logo.eps
DOC_FILES+=	tu-logo.jpg
DOC_FILES+=	tu-logo.mask.jpg

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
