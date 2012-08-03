# New ports collection makefile for: hs-wai-extra
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wai-extra
PORTVERSION=	1.2.0.5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Provides some basic WAI handlers and middleware

LICENSE=	MIT

USE_CABAL=	ansi-terminal blaze-builder>=0.2.1.4 blaze-builder-conduit>=0.4 \
		case-insensitive>=0.2 conduit>=0.4 data-default>=0.3 \
		fast-logger>=0.0.2 http-types>=0.6 network>=2.2.1.5 \
		resourcet>=0.3 stringsearch>=0.3 text>=0.7 transformers>=0.2.2 \
		wai>=1.2 zlib-conduit>=0.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
