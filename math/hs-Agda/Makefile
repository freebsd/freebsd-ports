# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	Agda
PORTVERSION=	2.3.2
PORTREVISION=	5
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Dependently typed functional programming language and proof assistant

USE_CABAL=	geniplate>=0.6.0.3 hashable>=1.1 hashtables \
		haskeline>=0.6.3.2 haskell-src-exts>=1.9.6 mtl \
		QuickCheck>=2.3 parallel syb>=0.1 unordered-containers>=0.2 \
		xhtml zlib>=0.4.0.1
USE_ALEX=	yes
USE_HAPPY=	yes
USES=		iconv

EXECUTABLE=	agda-mode agda

INSTALL_PORTDATA=	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DATADIR}; \
			 cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

OPTIONS_DEFINE=		EPIC

EPIC_DESC=		Install the Epic compiler

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEPIC}
CONFIGURE_ARGS+=	--flags="epic"
USE_CABAL+=		epic>=0.1.13
.else
CONFIGURE_ARGS+=	--flags="-epic"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
