# $FreeBSD$

PORTNAME=	yesod-persistent
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Some helpers for using Persistent from Yesod

LICENSE=	MIT

USE_CABAL=	blaze-builder conduit lifted-base persistent>=1.2 \
		persistent-template>=1.2 pool-conduit resourcet \
		transformers>=0.2.2 yesod-core>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
