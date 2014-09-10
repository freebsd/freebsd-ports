# $FreeBSD$

PORTNAME=	yesod
PORTVERSION=	1.2.6.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT

USE_CABAL=	aeson blaze-html>=0.5 blaze-markup>=0.5.1 conduit-extra \
		data-default fast-logger monad-control>=0.3 monad-logger \
		safe shakespeare>=2.0 text unordered-containers wai>=1.3 \
		wai-extra>=1.3 warp>=1.3 yaml yesod-auth>=1.2 \
		yesod-core>=1.2.2 yesod-form>=1.3 yesod-persistent>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
