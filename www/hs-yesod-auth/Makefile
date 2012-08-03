# New ports collection makefile for: hs-yesod-auth
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-auth
PORTVERSION=	1.0.2.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication for Yesod

LICENSE=	MIT

USE_CABAL=	aeson>=0.5 authenticate>=1.2 blaze-html>=0.5 blaze-markup>=0.5.1 \
		hamlet>=1.0 http-conduit>=1.4.1.1 lifted-base>=0.1 \
		mime-mail>=0.3 persistent>=0.9 persistent-template>=0.9 \
		pureMD5>=2.0 pwstore-fast>=2.2 random>=1.0.0.2 SHA>=1.4.1.3 \
		shakespeare-css>=1.0 text>=0.7 transformers>=0.2.2 \
		unordered-containers wai>=1.2 yesod-core>=1.0 yesod-form>=1.0 \
		yesod-json>=1.0 yesod-persistent>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
