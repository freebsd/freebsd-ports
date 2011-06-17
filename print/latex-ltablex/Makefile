# New ports collection makefile for:	print/latex-ltablex
# Date created:		14 April 2011
# Whom:			Raphael Kubo da Costa (kubito@gmail.com)
#
# $FreeBSD$

PORTNAME=	ltablex
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib
PKGNAMEPREFIX=	latex-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	latex

MAINTAINER=	kubito@gmail.com
COMMENT=	Combines the features of both the tabularx and longtable packages

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

USE_ZIP=	YES
NO_BUILD=	YES
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR} \
		TEXMFDIR=${TEXMFDIR}

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}

CLASS_FILES=	ltablex.sty
PORTDOCS=	ltablex.pdf ltablex.tex

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
