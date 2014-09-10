# $FreeBSD$

PORTNAME=	tls
PORTVERSION=	1.2.8
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	TLS/SSL protocol native implementation (Server and Client)

LICENSE=	BSD3CLAUSE

USE_CABAL=	asn1-encoding asn1-types>=0.2.0 byteable cereal>=0.4 \
		cipher-aes>=0.2 cipher-des cipher-rc4 crypto-cipher-types>=0.0.8 \
		crypto-numbers crypto-pubkey>=0.2.4 crypto-pubkey-types>=0.4 \
		crypto-random>=0.0 cryptohash>=0.6 data-default-class \
		mtl network x509>=1.4.3 x509-store>=1.4.4 x509-validation>=1.5.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
