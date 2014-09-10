# $FreeBSD$

PORTNAME=	x509-validation
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	X.509 Certificate and CRL validation

LICENSE=	BSD3CLAUSE

USE_CABAL=	asn1-encoding>=0.8 asn1-types>=0.2 byteable crypto-pubkey>=0.1.4 \
		crypto-pubkey-types>=0.4 cryptohash>=0.9 data-default-class \
		mtl network pem>=0.1 x509>=1.4.7 x509-store>=1.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
