# $FreeBSD$

PORTNAME=	http-conduit
PORTVERSION=	2.3.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client package with conduit interface and HTTPS support

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson conduit conduit-extra http-client http-client-tls \
		http-types lifted-base monad-control mtl resourcet

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
