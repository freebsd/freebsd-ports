# New ports collection makefile for:	hs-opengl-ghc
# Date created:				2008-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	2.4.0.1
CATEGORIES=	x11-toolkits haskell
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	OpenGL bindings for Haskell programs

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	GLURaw>=1.1.0.0 ObjectName OpenGLRaw>=1.1.0.0 StateVar Tensor

MASTER_SITES=	http://hackage.haskell.org/packages/archive/OpenGL/${PORTVERSION}/
DISTNAME=	OpenGL-${PORTVERSION}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
