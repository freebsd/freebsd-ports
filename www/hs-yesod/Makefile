# $FreeBSD$

PORTNAME=	yesod
PORTVERSION=	1.1.7.2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Creation of type-safe, RESTful web applications

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 base64-bytestring blaze-builder>=0.2.1.4 \
		blaze-html>=0.5 blaze-markup>=0.5.1 conduit>=0.5.1 file-embed \
		fsnotify>=0.0 ghc-paths>=0.1 hamlet>=1.1 http-conduit \
		http-reverse-proxy>=0.1.0.4 http-types>=0.7 lifted-base \
		monad-control>=0.3 network network-conduit \
		optparse-applicative>=0.4 parsec>=2.1 project-template>=0.1.1 \
		resourcet>=0.3 shakespeare>=1.0.2 shakespeare-css>=1.0.2 \
		shakespeare-js>=1.0.2 shakespeare-text>=1.0 split>=0.2 \
		system-fileio>=0.3 system-filepath>=0.4 tar>=0.4 text>=0.11 \
		transformers>=0.2.2 unix-compat>=0.2 unordered-containers \
		wai>=1.3 wai-extra>=1.3 warp>=1.3 yaml>=0.8 yesod-auth>=1.1 \
		yesod-core>=1.1.5 yesod-default>=1.1.3 yesod-form>=1.1 \
		yesod-json>=1.1 yesod-persistent>=1.1 zlib>=0.5

EXECUTABLE=	yesod yesod-ar-wrapper yesod-ghc-wrapper yesod-ld-wrapper

IGNORE_DYNAMIC=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
