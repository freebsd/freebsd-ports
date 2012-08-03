# New ports collection makefile for: hs-authenticate
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	authenticate
PORTVERSION=	1.2.1.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication methods for Haskell web applications

LICENSE=	BSD

USE_CABAL=	aeson>=0.5 attoparsec blaze-builder blaze-builder-conduit>=0.4 \
		case-insensitive>=0.2 conduit>=0.4 http-conduit>=1.4 \
		http-types>=0.6 monad-control>=0.3 network resourcet>=0.3 \
		tagsoup>=0.12 text transformers>=0.1 unordered-containers \
		xml-conduit>=0.7

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
