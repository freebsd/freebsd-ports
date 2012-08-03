# New ports collection makefile for: hs-Agda
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda
PORTVERSION=	2.3.0.1
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A dependently typed functional programming language and proof assistant

CABAL_SETUP=	Setup.hs

USE_CABAL=	hashable hashtables haskeline>=0.6.3.2 \
		haskell-src-exts>=1.9.6 mtl QuickCheck>=2.3 syb>=0.1 \
		xhtml zlib>=0.4.0.1
USE_ALEX=	yes
USE_HAPPY=	yes
USE_ICONV=	yes

EXECUTABLE=	agda-mode

INSTALL_PORTDATA=	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DATADIR}; \
			 cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DATADIR})

SHOW_PKGMSG=	yes

OPTIONS_DEFINE=		USE_LOCALE EPIC

USE_LOCALE_DESC=	Use encoding specified by the locale
EPIC_DESC=		Install the Epic compiler

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSE_LOCALE}
CONFIGURE_ARGS+=	--flags="use-locale"
.else
CONFIGURE_ARGS+=	--flags="-use-locale"
.endif

.if ${PORT_OPTIONS:MEPIC}
CONFIGURE_ARGS+=	--flags="epic"
USE_CABAL+=		epic>=0.1.13
.else
CONFIGURE_ARGS+=	--flags="-epic"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
