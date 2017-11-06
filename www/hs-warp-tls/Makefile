# $FreeBSD$

PORTNAME=	warp-tls
PORTVERSION=	3.2.4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP over SSL/TLS support for Warp via the TLS package

LICENSE=	MIT

USE_CABAL=	cprng-aes>=0.5.0 data-default-class>=0.0.1 network>=2.2.1 \
		streaming-commons tls>=1.2.16 tls-session-manager wai>=3.0 warp>=3.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
