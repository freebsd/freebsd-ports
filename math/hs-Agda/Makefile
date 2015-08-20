# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	Agda
PORTVERSION=	2.4.2.3
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant

USE_CABAL=	base-orphans>=0.3.1 boxes>=0.1.3 cpphs data-hash>=0.2.0.0 \
		edit-distance>=0.2.1.2 equivalence>=0.2.5 \
		geniplate-mirror>=0.6.0.6 hashable>=1.1.2.3 hashtables>=1.0 \
		haskell-src-exts>=1.16.0.1 mtl>=2.1.1 parallel QuickCheck>=2.8 \
		strict>=0.3.2 text>=0.11 transformers-compat>=0.3.3.2 \
		unordered-containers>=0.2 zlib>=0.4.0.1

USE_ALEX=	yes
USE_HAPPY=	yes
USES=		iconv:translit

EXECUTABLE=	agda-mode agda

_PRIMITIVE=	Primitive.agdai

INSTALL_PORTDATA=	${INSTALL_DATA} \
			    ${DISTDIR}/${DIST_SUBDIR}/${_PRIMITIVE}.${PORTVERSION} \
			    ${STAGEDIR}${DATADIR}/lib/prim/Agda/${_PRIMITIVE}

FLAGS_ENABLE=		cpphs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

MASTER_SITES+=	LOCAL/pgj:primitive
DISTFILES+=	${_PRIMITIVE}.${PORTVERSION}:primitive

.include <bsd.port.mk>
