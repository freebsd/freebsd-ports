# $FreeBSD$

PORTNAME=	nonce
PORTVERSION=	1.0.7
PORTREVISION=	2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Generate cryptographic nonces

LICENSE=	BSD3CLAUSE

USE_CABAL=	base64-bytestring cprng-aes>=0.5 crypto-random entropy>=0.3.7 \
		unliftio

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
