# $FreeBSD$

PORTNAME=	http-client-tls
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	http-client backend using the connection package and tls library

LICENSE=	MIT

USE_CABAL=	connection>=0.2.2 data-default-class http-client>=0.3.5 \
		network tls>=1.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
