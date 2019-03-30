# $FreeBSD$

PORTNAME=	tls
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	TLS/SSL protocol native implementation (Server and Client)

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	asn1-encoding asn1-types>=0.2.0 async byteable cereal>=0.4 \
		cryptonite>=0.3 data-default-class memory mtl network \
		x509>=1.6 x509-store>=1.6 x509-validation>=1.6

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
