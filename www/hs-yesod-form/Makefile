# New ports collection makefile for: hs-yesod-form
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-form
PORTVERSION=	1.0.0.4
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Form handling support for Yesod Web Framework

LICENSE=	MIT

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-html>=0.5 blaze-markup>=0.5.1 \
		data-default>=0.3 email-validate>=0.2.6 hamlet>=1.0 network>=2.2 \
		persistent>=0.9 shakespeare-css>=1.0 shakespeare-js>=1.0 \
		text>=0.9 transformers>=0.2.2 wai>=1.2 xss-sanitize>=0.3.0.1 \
		yesod-core>=1.0 yesod-persistent>=1.0

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
