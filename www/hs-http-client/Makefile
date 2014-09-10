# $FreeBSD$

PORTNAME=	http-client
PORTVERSION=	0.3.6.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client engine

LICENSE=	MIT

USE_CABAL=	base64-bytestring>=1.0 blaze-builder>=0.3 case-insensitive>=1.0 \
		cookie data-default-class exceptions>=0.4 http-types>=0.8 \
		mime-types network>=2.3 publicsuffixlist random \
		streaming-commons>=0.1.0.2 text>=0.11

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
