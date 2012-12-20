# $FreeBSD$

PORTNAME=	yesod-auth
PORTVERSION=	1.1.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication for Yesod

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 authenticate>=1.3 blaze-html>=0.5 \
		blaze-markup>=0.5.1 hamlet>=1.1 http-conduit>=1.5 \
		lifted-base>=0.1 mime-mail>=0.3 network persistent>=1.0 \
		persistent-template>=1.0 pureMD5>=2.0 pwstore-fast>=2.2 \
		random>=1.0.0.2 SHA>=1.4.1.3 shakespeare-css>=1.0 \
		shakespeare-js>=1.0.2 text>=0.7 transformers>=0.2.2 \
		unordered-containers wai>=1.3 yesod-core>=1.1 yesod-form>=1.1 \
		yesod-json>=1.1 yesod-persistent>=1.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
