# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	Agda
PORTVERSION=	2.4.0.2
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant

USE_CABAL=	boxes>=0.1.3 data-hash>=0.2.0.0 equivalence>=0.2.4 \
		geniplate>=0.6.0.3 hashable hashtables>=1.0 \
		haskell-src-exts>=1.9.6 mtl>=2.1.1 parallel QuickCheck>=2.6 \
		STMonadTrans>=0.3.2 strict>=0.3.2 text>=0.11 \
		unordered-containers>=0.2 zlib>=0.4.0.1
USE_ALEX=	yes
USE_HAPPY=	yes
USES=		iconv:translit

EXECUTABLE=	agda-mode agda

INSTALL_PORTDATA=	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DATADIR}

FLAGS_DEFINE=		EPIC

EPIC_DESC=		Install the Epic compiler
EPIC_FLAG_ENABLE=	epic
EPIC_FLAG_CABAL=	epic>=0.1.13

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
