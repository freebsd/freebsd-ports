# $FreeBSD$

PORTNAME=	http-conduit
PORTVERSION=	1.9.3
PORTREVISION=	3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP client package with conduit interface and HTTPS support

LICENSE=	BSD

USE_CABAL=	asn1-data>=0.5.1 base64-bytestring>=0.1 blaze-builder>=0.2.1 \
		blaze-builder-conduit>=0.5 case-insensitive>=0.2 \
		certificate>=1.3 conduit>=0.5.5 cookie>=0.4 cprng-aes>=0.3 \
		data-default failure>=0.1 http-types>=0.7 lifted-base>=0.1 \
		mime-types>=0.1 monad-control>=0.3 mtl network>=2.3 \
		publicsuffixlist>=0.0.3 random regex-compat resourcet>=0.3 \
		socks>=0.4 text tls>=1.0.0 tls-extra>=0.5.0 transformers>=0.2 \
		transformers-base>=0.4 utf8-string>=0.3.4 void>=0.5.5 \
		zlib-conduit>=0.5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
