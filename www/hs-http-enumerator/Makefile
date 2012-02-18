# New ports collection makefile for: hs-http-enumerator
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	http-enumerator
PORTVERSION=	0.7.2.5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client with enumerator interface and HTTPS support

LICENSE=	BSD

USE_CABAL=	asn1-data>=0.5.1 attoparsec>=0.8.0.2 \
		attoparsec-enumerator>=0.2.0.4 base64-bytestring>=0.1 \
		blaze-builder>=0.2.1 blaze-builder-enumerator>=0.2 \
		case-insensitive>=0.2 certificate>=0.7 cprng-aes>=0.2 \
		data-default>=0.3 enumerator>=0.4.9 failure>=0.1 \
		http-types>=0.6 monad-control>=0.2 network>=2.3 tls>=0.8.1 \
		tls-extra>=0.4 transformers>=0.2 utf8-string>=0.3.4 \
		zlib-enum>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
