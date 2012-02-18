# New ports collection makefile for: hs-yesod-auth
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-auth
PORTVERSION=	0.7.9
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Authentication for Yesod

LICENSE=	BSD

USE_CABAL=	aeson>=0.3 authenticate>=0.10.4 blaze-html>=0.4.1.3 \
		control-monad-attempt>=0.3.0 hamlet>=0.10 http-enumerator>=0.6 \
		mime-mail>=0.3 persistent>=0.6 persistent-template>=0.6 \
		pureMD5>=2.0 pwstore-fast>=2.2 SHA>=1.4.1.3 \
		shakespeare-css>=0.10 text>=0.7 transformers>=0.2.2 \
		unordered-containers wai>=0.4 yesod-core>=0.9.3.4 \
		yesod-form>=0.3 yesod-json>=0.2 yesod-persistent>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
