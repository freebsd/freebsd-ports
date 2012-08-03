# New ports collection makefile for: hs-http-conduit
# Date created:        December 30, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	http-conduit
PORTVERSION=	1.4.1.10
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client package with conduit interface and HTTPS support

LICENSE=	BSD

USE_CABAL=	asn1-data>=0.5.1 attoparsec>=0.8.0.2 attoparsec-conduit>=0.4 \
		base64-bytestring>=0.1 blaze-builder>=0.2.1 \
		blaze-builder-conduit>=0.4 case-insensitive>=0.2 \
		certificate>=1.2 conduit>=0.4.1 cookie>=0.4 cprng-aes>=0.2 \
		data-default>=0.3 failure>=0.1 http-types>=0.6 \
		lifted-base>=0.1 monad-control>=0.3 mtl network>=2.3 \
		regex-compat resourcet>=0.3 socks>=0.4 text tls>=0.9.3 \
		tls-extra>=0.4.5 transformers>=0.2 transformers-base>=0.4 \
		utf8-string>=0.3.4 void>=0.5.5 zlib-conduit>=0.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
