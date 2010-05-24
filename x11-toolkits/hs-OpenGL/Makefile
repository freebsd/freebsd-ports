# New ports collection makefile for:	hs-opengl-ghc
# Date created:				2008-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	OpenGL
PORTVERSION=	2.4.0.1
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	OpenGL bindings for Haskell programs

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	GLURaw>=1.1.0.0 ObjectName OpenGLRaw>=1.1.0.0 StateVar Tensor

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
