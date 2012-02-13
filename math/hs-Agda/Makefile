# New ports collection makefile for: hs-Agda
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda
PORTVERSION=	2.3.0
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A functional programming language and proof assistant

CABAL_SETUP=	Setup.hs
USE_CABAL=	binary>=0.4.4 hashable>=1.1 hashtables>=1.0 haskeline>=0.6.3.2 \
		haskell-src-exts>=1.9.6 mtl>=2 QuickCheck>=2.3 syb \
		utf8-string>=0.3 xhtml>=3000.2 zlib>=0.4.0.1

USE_ALEX=	yes
USE_HAPPY=	yes
USE_ICONV=	yes

EXECUTABLE=	agda-mode

INSTALL_PORTDATA=	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DATADIR}; \
			 cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DATADIR})

SHOW_PKGMSG=	yes

OPTIONS=	USE_LOCALE "Use encoding specified by the locale" off \
		EPIC       "Install the Epic compiler" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_USE_LOCALE)
CONFIGURE_ARGS+=	--flags="use-locale"
.else
CONFIGURE_ARGS+=	--flags="-use-locale"
.endif

.if defined(WITH_EPIC)
CONFIGURE_ARGS+=	--flags="epic"
USE_CABAL+=		epic>=0.1.13
.else
CONFIGURE_ARGS+=	--flags="-epic"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
