# New ports collection makefile for: hs-gtkglext
# Date created:        March 13, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtkglext
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to the GTK+ OpenGL Extension

LIB_DEPENDS=	gtkglext:${PORTSDIR}/x11-toolkits/gtkglext

LICENSE=	LGPL21
FILE_LICENSE=	COPYING

CABAL_SETUP=	Setup.hs
USE_CABAL=	cairo>=0.12 glib>=0.12 gtk>=0.12 mtl pango>=0.12

PORTDATA=	*

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
