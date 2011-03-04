# New ports collection makefile for:  latex-acm
# Date created:                       Jan 25 2011
# Whom:                               Eygene Ryabinkin <rea@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	latex-acm
PORTVERSION=	1.1
CATEGORIES=	print
MASTER_SITES=	http://www.acm.org/publications/latex_style/ \
		http://dist.codelabs.ru/fbsd/latex-acm/
DISTFILES=	acm-small-v1-1.zip \
		acm-large-v1-1.zip

MAINTAINER=	rea@FreeBSD.org
COMMENT=	LaTeX styles for ACM journals

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal

USE_ZIP=	yes
NO_BUILD=	yes

TEXMFLOCAL=	share/texmf-local
TEXMFLOCAL_LSR=	${LOCALBASE}/${TEXMFLOCAL}/ls-R
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
LATEXDIR=	${TEXMFLOCAL}/tex/latex/${PORTNAME:S/^latex-//}
BIBTEXDIR=	${TEXMFLOCAL}/bibtex/bst/${PORTNAME:S/^latex-//}
WRKSRC=		${WRKDIR}
CLASS_FILES=	acmlarge.cls acmsmall.cls
STYLE_FILES=	algorithm2e.sty
BIB_FILES=	acmlarge.bst acmsmall.bst
PORTEXAMPLES=	acmlarge-sample.tex acmlarge-sample.pdf acmlarge-sample.bbl \
		acmlarge-mouse.eps acmlarge-mouse.pdf acmlarge-sam.bib \
		acmsmall-sample.tex acmsmall-sample.pdf acmsmall-sample.bbl \
		acmsmall-mouse.eps acmsmall-mouse.pdf acmsmall-sam.bib
PORTDOCS=	acmlarge-guide.pdf acmsmall-guide.pdf

PLIST_FILES=	${CLASS_FILES:S@^@${LATEXDIR}/@} \
		${STYLE_FILES:S@^@${LATEXDIR}/@} \
		${BIB_FILES:S@^@${BIBTEXDIR}/@}
PLIST_DIRS=	${LATEXDIR} ${BIBTEXDIR}
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		TEXMFLOCAL=${TEXMFLOCAL}

do-install:
	${MKDIR} ${PREFIX}/${LATEXDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${LATEXDIR}
	${INSTALL_DATA} ${STYLE_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${LATEXDIR}
	${MKDIR} ${PREFIX}/${BIBTEXDIR}
	${INSTALL_DATA} ${BIB_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${BIBTEXDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/@} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
