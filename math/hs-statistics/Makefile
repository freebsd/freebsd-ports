# New ports collection makefile for: hs-statistics
# Date created:        January 03 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	statistics
PORTVERSION=	0.10.1.0
PORTREVISION=	1
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A library of statistical types, data, and functions

LICENSE=	BSD

USE_CABAL=	erf math-functions>=0.1.1 monad-par>=0.1.0.1 \
		mwc-random>=0.11.0.0 primitive>=0.3 vector>=0.7.1 \
		vector-algorithms>=0.4

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
