# $FreeBSD$

PORTNAME=	certificate
PORTVERSION=	1.3.9
PORTREVISION=	4
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Certificates and Key Reader/Writer

LICENSE=	BSD3CLAUSE

USE_CABAL=	asn1-data>=0.7.1 crypto-pubkey-types>=0.4 cryptohash \
		mtl pem>=0.1

FLAGS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=		Build the executable
EXECUTABLE_FLAG_ENABLE=		executable
EXECUTABLE_FLAG_CABAL=		cmdargs text>=0.11 cryptohash crypto-pubkey
EXECUTABLE_FLAG_EXECUTABLE=	certificate

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
