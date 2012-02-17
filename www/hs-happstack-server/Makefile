# New ports collection makefile for: hs-happstack-server
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	happstack-server
PORTVERSION=	6.2.5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web-related tools and services

LICENSE=	BSD
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	blaze-html>=0.3 happstack-data>=6.0 happstack-util>=6.0 \
		hslogger>=1.0.2 html MaybeT mtl>=1.1 network>=2.2.3 parsec \
		sendfile>=0.7.1 text>=0.10 utf8-string>=0.3.4 xhtml zlib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
