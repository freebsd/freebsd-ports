# New ports collection makefile for: hs-statistics
# Date created:        January 03 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	statistics
PORTVERSION=	0.8.0.5
PORTREVISION=	4
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell library of statistical types, data, and functions

LICENSE=	BSD

USE_CABAL=	erf mwc-random>=0.8.0.3 primitive>=0.3 vector>=0.7 \
		vector-algorithms>=0.4

PORTDATA=		*
INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
