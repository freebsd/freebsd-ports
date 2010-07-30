# New ports collection makefile for: hs-statistics
# Date created:        January 03 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	statistics
PORTVERSION=	0.6.0.2
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell library of statistical types, data, and functions

USE_HACKAGE=	erf mwc-random>=0.7.0.0 primitive>=0.3 vector>=0.6.0.2 vector-algorithms>=0.3.2

PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
