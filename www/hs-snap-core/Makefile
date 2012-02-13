# New ports collection makefile for: hs-snap-core
# Date created:        September 19, 2010
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	snap-core
PORTVERSION=	0.7.0.1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Snap: A Haskell Web Framework (Core)

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 \
		base16-bytestring blaze-builder>=0.2.1.4 \
		blaze-builder-enumerator>=0.2 bytestring-nums \
		case-insensitive>=0.3 deepseq>=1.1 dlist>=0.5 \
		enumerator>=0.4.13.1 HUnit>=1.2 \
		MonadCatchIO-transformers>=0.2.1 mtl>=2.0 \
		mwc-random>=0.10 regex-posix text>=0.11 transformers>=0.2 \
		unix-compat>=0.2 unordered-containers>=0.1.4.3 vector>=0.6 \
		zlib-enum>=0.2.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
