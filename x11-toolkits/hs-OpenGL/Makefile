# New ports collection makefile for:	hs-opengl-ghc
# Date created:				2008-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	OpenGL
PORTVERSION=	2.2.3.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A binding for the OpenGL graphics system

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_GL=		gl glut

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
