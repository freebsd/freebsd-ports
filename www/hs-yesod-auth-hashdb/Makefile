# $FreeBSD$

PORTNAME=	yesod-auth-hashdb
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication plugin for Yesod

LICENSE=	MIT

USE_CABAL=	cryptohash>=0.8 persistent>=2.1 pwstore-fast>=2.2 text>=0.7 \
		yesod-auth>=1.4 yesod-core>=1.4 yesod-form>=1.4 \
		yesod-persistent>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
