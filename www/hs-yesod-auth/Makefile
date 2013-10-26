# $FreeBSD$

PORTNAME=	yesod-auth
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication for Yesod

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 authenticate>=1.3 blaze-html>=0.5 \
		blaze-markup>=0.5.1 data-default email-validate>=1.0 \
		file-embed hamlet>=1.1 http-conduit>=1.5 http-types \
		lifted-base>=0.1 mime-mail>=0.3 network persistent>=1.2 \
		persistent-template>=1.2 pureMD5>=2.0 pwstore-fast>=2.2 \
		random>=1.0.0.2 SHA>=1.4.1.3 shakespeare-css>=1.0 \
		shakespeare-js>=1.0.2 text>=0.7 transformers>=0.2.2 \
		unordered-containers wai>=1.4 yesod-core>=1.2 yesod-form>=1.3 \
		yesod-persistent>=1.2

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
