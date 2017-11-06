# $FreeBSD$

PORTNAME=	DAV
PORTVERSION=	1.3.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	RFC 4918 WebDAV support

LICENSE=	GPLv3

USE_CABAL=	case-insensitive>=0.4 data-default either>=4.1 \
		exceptions http-client>=0.2 http-client-tls>=0.2 \
		http-types>=0.7 lens>=3.0 mtl>=2.1 network>=2.6 \
		network-uri>=2.6 optparse-applicative>=0.10.0 \
		transformers-base utf8-string xml-conduit>=1.0 \
		xml-hamlet>=0.4

EXECUTABLE=	hdav

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
