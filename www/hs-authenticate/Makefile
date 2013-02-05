# $FreeBSD$

PORTNAME=	authenticate
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication methods for Haskell web applications

LICENSE=	BSD

USE_CABAL=	aeson>=0.5 attoparsec blaze-builder blaze-builder-conduit>=0.5 \
		case-insensitive>=0.2 conduit>=0.5 http-conduit>=1.5 \
		http-types>=0.6 monad-control>=0.3 network resourcet>=0.3 \
		tagsoup>=0.12 text transformers>=0.1 unordered-containers \
		xml-conduit>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
