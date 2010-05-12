# New ports collection makefile for: hs-Agda
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	jacula@gmail.com
COMMENT=	A functional programming language and proof assistant

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	binary>=0.4.4 haskeline>=0.3 QuickCheck>=2.1.0.2 \
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
