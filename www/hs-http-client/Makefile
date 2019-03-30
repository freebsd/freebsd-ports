# $FreeBSD$

PORTNAME=	http-client
PORTVERSION=	0.5.12.1
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client engine, intended as a base layer for more user-friendly packages

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	base64-bytestring>=1.0 blaze-builder>=0.3 case-insensitive>=1.0 \
		cookie data-default-class exceptions>=0.4 http-types>=0.8 \
		memory mime-types network>=2.6 network-uri>=2.6 random \
		streaming-commons>=0.1.0.2

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
