# New ports collection makefile for: hs-wx
# Date created:        January 26, 2012
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wx
PORTVERSION=	0.13.2.1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	wxHaskell


USE_CABAL=	stm wxcore>=0.13.1

BUILD_DEPENDS+=	wxgtk2-unicode>=2.8:${PORTSDIR}/x11-toolkits/wxgtk28-unicode \
		wxgtk2-unicode-contrib>=2.8:${PORTSDIR}/x11-toolkits/wxgtk28-unicode-contrib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
