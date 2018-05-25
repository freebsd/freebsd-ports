# $FreeBSD$

PORTNAME=	http-api-data
PORTVERSION=	0.3.8.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Convert Haskell data types to and from HTTP API data

LICENSE=	GPLv3

USE_CABAL=	attoparsec attoparsec-iso8601 hashable http-types \
		time-locale-compat unordered-containers uri-bytestring \
		uuid-types

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
