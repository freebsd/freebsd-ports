# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	Agda
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant

USE_CABAL=	EdisonCore boxes data-hash edit-distance equivalence \
		geniplate-mirror gitrev hashable hashtables ieee754 \
		mtl murmur-hash parallel regex-tdfa strict \
		unordered-containers zlib

USE_ALEX=	yes
USE_HAPPY=	yes
USE_CPPHS=	yes
USES=		iconv:translit

EXECUTABLE=	agda-mode agda

FLAGS_ENABLE=		cpphs

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	DATADIR=${DATADIR}

IGNORE=		Doesn't build with recent GHC version

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
