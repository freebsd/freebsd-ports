# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	textproc haskell
PKGNAMEPREFIX=

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A general markup converter

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	utf8-string>=0.3 zip-archive>=0.1.1.4

MAN1=		pandoc.1 markdown2pdf.1 html2markdown.1 hsmarkdown.1

EXECUTABLE=	pandoc markdown2pdf hsmarkdown

PORTDATA=	*

OPTIONS=	HIGHLIGHTING "Syntax highlighting support" off

.include <bsd.port.pre.mk>

.if defined(WITH_HIGHLIGHTING)
CONFIGURE_ARGS+=	--flags="highlighting"
USE_HACKAGE+=		highlighting-kate
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.post.mk>
