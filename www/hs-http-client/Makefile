# $FreeBSD$

PORTNAME=	http-client
PORTVERSION=	0.5.7.0
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client engine, intended as a base layer for more user-friendly packages

LICENSE=	MIT

USE_CABAL=	base64-bytestring>=1.0 blaze-builder>=0.3 case-insensitive>=1.0 \
		cookie data-default-class exceptions>=0.4 http-types>=0.8 \
		mime-types network>=2.6 network-uri>=2.6 random \
		streaming-commons>=0.1.0.2 text>=0.11

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
