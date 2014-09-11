# $FreeBSD$

PORTNAME=	yesod-bin
PORTVERSION=	1.2.12.3
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Yesod helper executable

LICENSE=	MIT

USE_CABAL=	attoparsec>=0.10 base64-bytestring blaze-builder>=0.2.1.4 \
		conduit>=0.5 conduit-extra data-default-class file-embed \
		fsnotify>=0.0 ghc-paths>=0.1 http-conduit \
		http-reverse-proxy>=0.1.1 http-types>=0.7 lifted-base \
		network optparse-applicative>=0.5 parsec>=2.1 \
		project-template>=0.1.1 resourcet>=0.3 shakespeare>=1.0.2 \
		split>=0.2 streaming-commons system-fileio>=0.3 \
		system-filepath>=0.4 tar>=0.4 text>=0.11 unix-compat>=0.2 \
		unordered-containers wai>=1.4 wai-extra warp>=1.3.7.5 \
		yaml>=0.8 zlib>=0.5

EXECUTABLE=	yesod-ghc-wrapper yesod-ld-wrapper yesod-ar-wrapper yesod
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
