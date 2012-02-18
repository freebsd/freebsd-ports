# New ports collection makefile for: hs-authenticate
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	authenticate
PORTVERSION=	0.10.4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication methods for Haskell web applications

LICENSE=	BSD

USE_CABAL=	aeson>=0.3.2.11 attoparsec>=0.9 base64-bytestring>=0.1 \
		blaze-builder>=0.2 case-insensitive>=0.2 enumerator>=0.4.7 \
		failure>=0.0.0 http-enumerator>=0.6.5.4 http-types>=0.6 \
		network>=2.2.1 RSA>=1.0 SHA>=1.4 tagsoup>=0.12 text>=0.5 tls>=0.7 \
		transformers>=0.1 unordered-containers xml-enumerator>=0.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
