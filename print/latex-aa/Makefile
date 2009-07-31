# New ports collection makefile for:	print/latex-aa
# Date created:		13 November 2007
# Whom:			Koji Yokota (yokota@res.otaru-uc.ac.jp)
#
# $FreeBSD$
#

PORTNAME=	latex-aa
PORTVERSION=	6.1
PORTREVISION=	1
CATEGORIES=	print astro science
MASTER_SITES=	ftp://ftp.edpsciences.org/pub/aa/
DISTNAME=	aa-package
DIST_SUBDIR=	latex

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	LaTeX class for submission to "Astronomy and Astrophysics"

BUILD_DEPENDS=	${LOCALBASE}/share/texmf:${PORTSDIR}/print/teTeX-texmf \
		latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_GHOSTSCRIPT_BUILD=	yes
TEXMFDIR=	share/texmf
AADIR=		tex/latex/aa
AABIBDIR=	bibtex/bst/aa
AADOCSDIR=	doc/latex/aa
DOCFILES=	aa.dem aa.dvi aa.pdf aadoc.pdf readme.html readme.txt
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

pre-install:
	( cd ${WRKSRC}/${DISTNAME} && \
	  latex aa.dem && latex aa.dem && dvips aa.dvi && ps2pdf aa.ps )

do-install:
	( cd ${WRKSRC}/${DISTNAME} && \
	  ${COPYTREE_SHARE} "aa.cls" ${PREFIX}/${TEXMFDIR}/${AADIR} )
	( cd ${WRKSRC}/${DISTNAME}/bibtex/ && \
	  ${COPYTREE_SHARE} "aa.bst" ${PREFIX}/${TEXMFDIR}/${AABIBDIR} )
.if !defined(NOPORTDOCS)
	( cd ${WRKSRC}/${DISTNAME} && \
	  ${COPYTREE_SHARE} "${DOCFILES}" ${PREFIX}/${TEXMFDIR}/${AADOCSDIR} )
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
