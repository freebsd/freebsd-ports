# $FreeBSD$

PORTNAME=	authenticate
PORTVERSION=	1.3.2.6
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication methods for Haskell web applications

LICENSE=	BSD

USE_CABAL=	aeson>=0.5 attoparsec blaze-builder case-insensitive>=0.2 \
		conduit>=0.5 http-conduit>=1.5 http-types>=0.6 network \
		tagsoup>=0.12 text transformers>=0.1 unordered-containers \
		xml-conduit>=1.0

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
