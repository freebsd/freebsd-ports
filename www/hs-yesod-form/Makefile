# $FreeBSD$

PORTNAME=	yesod-form
PORTVERSION=	1.2.0.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Form handling support for Yesod Web Framework

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 crypto-api>=0.8 data-default \
		email-validate>=0.2.6 hamlet>=1.1 network>=2.2 \
		persistent>=1.0 shakespeare-css>=1.0 shakespeare-js>=1.0.2 \
		text>=0.9 transformers>=0.2.2 wai>=1.3 xss-sanitize>=0.3.0.1 \
		yesod-core>=1.1 yesod-persistent>=1.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
