# New ports collection makefile for: hs-yesod-form
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-form
PORTVERSION=	0.3.4.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Form handling support for Yesod Web Framework

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.2.1.4 blaze-html>=0.4.1.3 data-default>=0.3 \
		email-validate>=0.2.6 hamlet>=0.10 network>=2.2 \
		persistent>=0.6 shakespeare-css>=0.10 shakespeare-js>=0.10 \
		text>=0.9 transformers>=0.2.2 wai>=0.4 xss-sanitize>=0.3.0.1 \
		yesod-core>=0.9 yesod-persistent>=0.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
