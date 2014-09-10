# $FreeBSD$

PORTNAME=	yesod-form
PORTVERSION=	1.3.14
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Form handling support for Yesod Web Framework

LICENSE=	MIT

USE_CABAL=	aeson attoparsec>=0.10 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 byteable data-default email-validate>=1.0 \
		network>=2.2 persistent>=1.2 resourcet shakespeare text>=0.9 \
		wai>=1.3 xss-sanitize>=0.3.0.1 yesod-core>=1.2 \
		yesod-persistent>=1.2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
