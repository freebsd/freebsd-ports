# New ports collection makefile for:	hs-glut-ghc
# Date created:				2007-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	glut
PORTVERSION=	2.2.2.0
CATEGORIES=	x11-toolkits haskell
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell binding for the OpenGL Utility Toolkit

CABAL_SETUP=	Setup.hs
USE_HACKAGE=	OpenGL>=2.3 StateVar Tensor
USE_GL=		glut

MASTER_SITES=	http://hackage.haskell.org/packages/archive/GLUT/${PORTVERSION}/
DISTNAME=	GLUT-${PORTVERSION}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
