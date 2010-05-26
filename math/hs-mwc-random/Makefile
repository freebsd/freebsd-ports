# New ports collection makefile for: hs-mwc-random
# Date created:        January 03 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mwc-random
PORTVERSION=	0.4.1.1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, high quality pseudo random number generation in Haskell

USE_HACKAGE=	uvector>=0.1.0.4

PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
