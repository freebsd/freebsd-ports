# New ports collection makefile for:	print/latex-prettyref
# Date created:		19 November 2007
# Whom:			Koji Yokota (yokota@res.otaru-uc.ac.jp)
#
# $FreeBSD$
#

PORTNAME=	latex-prettyref
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib
DISTNAME=	${PORTNAME:S/^latex-//}
DIST_SUBDIR=	latex

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	Improved reference formatting for LaTeX2e

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

USE_ZIP=	yes
PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

TEXMFDIR?=	share/texmf
STYDIR?=		tex/latex/${PORTNAME:S/^latex-//}
DOCSDIR?=	doc/latex/${PORTNAME:S/^latex-//}
INSFILE=	${PORTNAME:S/^latex-//}.ins
STYFILE=	${PORTNAME:S/^latex-//}.sty
PDFFILE=	${PORTNAME:S/^latex-//}.pdf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr

do-build:
	@( cd ${WRKSRC} && tex ${INSFILE} )

do-install:
	@( cd ${WRKSRC} && \
	  ${MKDIR} ${PREFIX}/${TEXMFDIR}/${STYDIR} && \
	  ${COPYTREE_SHARE} "${STYFILE}" ${PREFIX}/${TEXMFDIR}/${STYDIR} )
.if !defined(NOPORTDOCS)
	@( cd ${WRKSRC} && \
	  ${MKDIR} ${PREFIX}/${TEXMFDIR}/${DOCSDIR} && \
	  ${COPYTREE_SHARE} "${PDFFILE}" ${PREFIX}/${TEXMFDIR}/${DOCSDIR} )
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
