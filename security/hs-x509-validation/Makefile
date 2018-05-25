# $FreeBSD$

PORTNAME=	x509-validation
PORTVERSION=	1.6.10
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	X.509 Certificate and CRL validation

LICENSE=	BSD3CLAUSE

USE_CABAL=	asn1-encoding>=0.9 asn1-types>=0.3 byteable cryptonite>=0.3 \
		data-default-class hourglass memory mtl network pem>=0.1 \
		x509>=1.6 x509-store>=1.6

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
