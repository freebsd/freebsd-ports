# New ports collection makefile for: hs-yesod-test
# Date created:        June 10, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	yesod-test
PORTVERSION=	0.2.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	integration testing for WAI/Yesod Applications

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 blaze-html>=0.5 blaze-markup>=0.5.1 \
		case-insensitive>=0.2 hspec>=1.1 html-conduit>=0.0.1 \
		http-types>=0.6 HUnit>=1.2 hxt>=9.1.6 network>=2.2 \
		persistent>=0.9 text transformers>=0.2.2 wai>=1.2 \
		wai-test>=1.2 xml-conduit>=0.7 xml-types>=0.3 \
		xml2html>=0.1.2.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
