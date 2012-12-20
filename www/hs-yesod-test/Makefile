# $FreeBSD$

PORTNAME=	yesod-test
PORTVERSION=	0.3.1.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Integration testing for WAI/Yesod Applications

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 blaze-html>=0.5 blaze-markup>=0.5.1 \
		case-insensitive>=0.2 hspec>=1.3 html-conduit>=0.1 \
		http-types>=0.7 HUnit>=1.2 monad-control network>=2.2 \
		persistent>=1.0 pool-conduit text transformers>=0.2.2 \
		wai>=1.3 wai-test>=1.3 xml-conduit>=1.0 xml-types>=0.3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
