# $FreeBSD$

PORTNAME=	yesod-test
PORTVERSION=	1.5.7
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Integration testing for WAI/Yesod Applications

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 blaze-builder blaze-html>=0.5 \
		blaze-markup>=0.5.1 case-insensitive>=0.2 cookie \
		hspec-core>=2.0 html-conduit>=0.1 http-types>=0.7 HUnit>=1.2 \
		monad-control network>=2.2 persistent>=1.0 pretty-show text wai>=3.0 \
		wai-extra xml-conduit>=1.0 xml-types>=0.3 yesod-core>=1.4

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
