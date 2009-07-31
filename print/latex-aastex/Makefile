# New ports collection makefile for:	print/latex-aastex
# Date created:		14 November 2007
# Whom:			Koji Yokota (yokota@res.otaru-uc.ac.jp)
#
# $FreeBSD$
#

PORTNAME=	latex-aastex
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	print astro science
MASTER_SITES=	ftp://ftp.iop.org/pub/journals/
DISTNAME=	aastex${PORTVERSION:S/.//}
DIST_SUBDIR=	latex

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	LaTeX class for American Astronomical Society (AAS) journals

BUILD_DEPENDS=	${LOCALBASE}/share/texmf:${PORTSDIR}/print/teTeX-texmf \
		dvips:${PORTSDIR}/print/dvipsk-tetex

USE_GHOSTSCRIPT=yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

TEXMFDIR=	share/texmf
CLSDIR=		tex/latex/aastex
DOCSDIR=	doc/latex/aastex
CLSFILES=	aastex.cls
DVIDOCS=	sample.dvi table.dvi
PSDOCS=		aasguide.ps aassymbols.ps
TXTDOCS=	README
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

pre-install:
.for _DVIDOC in ${DVIDOCS}
	( cd ${WRKSRC}/${DISTNAME} && \
	  dvips ${_DVIDOC} && ps2pdf ${_DVIDOC:S/.dvi/.ps/} )
.endfor
.for _PSDOC in ${PSDOCS}
	( cd ${WRKSRC}/${DISTNAME} && \
	  ps2pdf ${_PSDOC} )
.endfor

do-install:
	( cd ${WRKSRC}/${DISTNAME} && \
	  ${COPYTREE_SHARE} "${CLSFILES}" ${PREFIX}/${TEXMFDIR}/${CLSDIR} )
.if !defined(NOPORTDOCS)
	( cd ${WRKSRC}/${DISTNAME} && \
	  ${COPYTREE_SHARE} "${DVIDOCS} ${DVIDOCS:S/.dvi/.pdf/} ${PSDOCS:S/.ps/.dvi/} ${PSDOCS:S/.ps/.pdf/} ${TXTDOCS}" ${PREFIX}/${TEXMFDIR}/${DOCSDIR} )
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
