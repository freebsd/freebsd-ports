# $FreeBSD$

PORTNAME=	DAV
PORTVERSION=	0.8
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	RFC 4918 WebDAV support

LICENSE=	GPLv3

USE_CABAL=	case-insensitive>=0.4 either>=4.1 errors http-client>=0.2 \
		http-client-tls>=0.2 http-types>=0.7 lens>=3.0 \
		lifted-base>=0.1 monad-control>=0.3.2 mtl>=2.1 network>=2.3 \
		optparse-applicative>=0.5.0 transformers-base \
		xml-conduit>=1.0 xml-hamlet>=0.4

EXECUTABLE=	hdav

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
