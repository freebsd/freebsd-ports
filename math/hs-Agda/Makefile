# New ports collection makefile for: hs-Agda
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda
PORTVERSION=	2.2.10
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A functional programming language and proof assistant

CABAL_SETUP=	Setup.hs
USE_CABAL=	binary>=0.4.4 haskeline>=0.6.3.2 haskell-src-exts>=1.9.6 \
		mtl>=2 QuickCheck>=2.3 syb utf8-string>=0.3 xhtml>=3000.2 \
		zlib>=0.4.0.1

USE_ALEX=	yes
USE_HAPPY=	yes
USE_ICONV=	yes

EXECUTABLE=	agda-mode

PORTDATA=		*
INSTALL_PORTDATA=	(cd ${WRKSRC} && ${INSTALL_DATA} README ${DATADIR}; \
			 cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DATADIR})

SHOW_PKGMSG=	yes

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
