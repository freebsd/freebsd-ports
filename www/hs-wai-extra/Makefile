# $FreeBSD$

PORTNAME=	wai-extra
PORTVERSION=	3.0.1.2
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Provides some basic WAI handlers and middleware

LICENSE=	MIT

USE_CABAL=	ansi-terminal base64-bytestring blaze-builder>=0.2.1.4 \
		case-insensitive>=0.2 data-default-class fast-logger>=2.1 \
		http-types>=0.7 lifted-base>=0.1.2 network>=2.2.1.5 \
		resourcet>=0.4.6 streaming-commons stringsearch>=0.3 \
		text>=0.7 void>=0.5 wai>=3.0 wai-logger>=2.0 word8

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
