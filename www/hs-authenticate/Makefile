# $FreeBSD$

PORTNAME=	authenticate
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication methods for Haskell web applications

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson>=0.5 attoparsec blaze-builder case-insensitive>=0.2 \
		conduit>=0.5 http-conduit>=1.5 http-types>=0.6 monad-control \
		network>=2.6 network-uri>=2.6 resourcet \
		tagstream-conduit>=0.5.5 unordered-containers \
		xml-conduit>=1.0

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
