# New ports collection makefile for: hs-GLURaw-ghc
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	GLURaw
PORTVERSION=	1.1.0.0
CATEGORIES=	x11-toolkits haskell
PKGNAMESUFFIX=	-ghc

MAINTAINER=	jacula@gmail.com
COMMENT=	A raw Haskell binding for the OpenGL Utility Toolkit

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	OpenGLRaw
USE_GL=		glu

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
