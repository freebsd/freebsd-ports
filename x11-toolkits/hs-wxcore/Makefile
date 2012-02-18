# New ports collection makefile for: hs-wxcore
# Date created:        January 26, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wxcore
PORTVERSION=	0.13.2.1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	wxHaskell core


CABAL_SETUP=	Setup.hs

USE_CABAL=	parsec stm wxdirect>0.12.1.2

BUILD_DEPENDS+=	wxgtk2-unicode>=2.8:${PORTSDIR}/x11-toolkits/wxgtk28-unicode \
		wxgtk2-unicode-contrib>=2.8:${PORTSDIR}/x11-toolkits/wxgtk28-unicode-contrib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
