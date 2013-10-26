# $FreeBSD$

PORTNAME=	snap-core
PORTVERSION=	0.9.3.1
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Snap: A Haskell Web Framework (core interfaces and types)

LICENSE=	BSD

USE_CABAL=	attoparsec>=0.10 attoparsec-enumerator>=0.3 \
		blaze-builder>=0.2.1.4 blaze-builder-enumerator>=0.2 \
		case-insensitive>=0.3 enumerator>=0.4.15 HUnit>=1.2 \
		MonadCatchIO-transformers>=0.2.1 mtl>=2.0 random>=1 \
		regex-posix>=0.95 text>=0.11 unix-compat>=0.2 \
		unordered-containers>=0.1.4.3 vector>=0.6 zlib-enum>=0.2.1

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
