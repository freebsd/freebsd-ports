# $FreeBSD$

PORTNAME=	yesod-form
PORTVERSION=	1.6.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Form handling support for Yesod Web Framework

LICENSE=	MIT

USE_CABAL=	aeson attoparsec>=0.10 blaze-builder>=0.2.1.4 blaze-html>=0.5 \
		blaze-markup>=0.5.1 byteable data-default email-validate>=1.0 \
		network>=2.6 network-uri>=2.6 persistent resourcet semigroups \
		shakespeare>=2.0 wai>=1.3 xss-sanitize>=0.3.0.1 \
		yesod-core>=1.4 yesod-persistent>=1.4

FLAGS_ENABLE=	network-uri

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
