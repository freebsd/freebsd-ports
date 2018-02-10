# $FreeBSD$

PORTNAME=	yesod-bin
PORTVERSION=	1.5.2.3
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Yesod helper executable

LICENSE=	MIT

USE_CABAL=	async attoparsec>=0.10 base64-bytestring \
		blaze-builder>=0.2.1.4 conduit>=1.2 conduit-extra \
		data-default-class file-embed fsnotify>=0.0 ghc-paths>=0.1 \
		http-client http-conduit>=2.1.4 http-reverse-proxy>=0.4 \
		http-types>=0.7 lifted-base network \
		optparse-applicative>=0.11 parsec>=2.1 \
		project-template>=0.1.1 resourcet>=0.3 safe-exceptions say shakespeare>=2.0 \
		split>=0.2 streaming-commons tar>=0.4 text>=0.11 \
		transformers-compat typed-process unix-compat>=0.2 unordered-containers \
		wai>=1.4 wai-extra warp>=1.3.7.5 warp-tls>=3.0.1 yaml>=0.8 \
		zlib>=0.5

EXECUTABLE=	yesod
STANDALONE=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
