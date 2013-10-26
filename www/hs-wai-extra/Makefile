# $FreeBSD$

PORTNAME=	wai-extra
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Provides some basic WAI handlers and middleware

LICENSE=	MIT

USE_CABAL=	ansi-terminal blaze-builder>=0.2.1.4 blaze-builder-conduit>=0.5 \
		base64-bytestring case-insensitive>=0.2 conduit>=0.5 \
		data-default date-cache>=0.3 fast-logger>=0.2 http-types>=0.7 \
		network>=2.2.1.5 resourcet>=0.3 stringsearch>=0.3 \
		text>=0.7 transformers>=0.2.2 void>=0.5 wai>=1.3 \
		wai-logger>=0.2 word8 zlib-conduit>=0.5

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
