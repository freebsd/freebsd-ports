# New ports collection makefile for: hs-tagsoup
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tagsoup
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell library for extracting information from HTML documents

CABAL_SETUP=	Setup.hs

EXECUTABLE=	tagsoup

PORTDATA=		*
INSTALL_PORTDATA=	cd ${WRKSRC} && \
			  ${INSTALL_DATA} ${WRKSRC}/tagsoup.htm ${DATADIR}

PORTEXAMPLES=		*
INSTALL_PORTEXAMPLES=	cd ${WRKSRC}/Example && \
			  ${COPYTREE_SHARE} \* ${EXAMPLESDIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
