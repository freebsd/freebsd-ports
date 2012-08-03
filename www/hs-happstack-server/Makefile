# New ports collection makefile for: hs-happstack-server
# Date created:        December 2, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	happstack-server
PORTVERSION=	7.0.3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web-related tools and services

LICENSE=	BSD
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs

USE_CABAL=	base64-bytestring blaze-html hslogger>=1.0.2 html \
		monad-control>=0.3 mtl>=2 network>=2.2.3 parsec \
		sendfile>=0.7.1 syb system-filepath>=0.3.1 text>=0.10 \
		transformers>=0.1.3 transformers-base>=0.4 utf8-string>=0.3.4 \
		xhtml zlib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
