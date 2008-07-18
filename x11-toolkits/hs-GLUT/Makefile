# New ports collection makefile for:	hs-glut-ghc
# Date created:				2007-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	glut
PORTVERSION=	2.1.1.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/GLUT/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	GLUT-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Compiler for the functional language Haskell

USE_GL=		glut

GHC_VERSION=	6.8.3
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		PORTNAME=${PORTNAME} \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		${LOCALBASE}/lib/ghc-${GHC_VERSION}/cabal/opengl-register.sh:${PORTSDIR}/x11-toolkits/hs-opengl-ghc
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4
RUN_DEPENDS+=	${LOCALBASE}/lib/ghc-${GHC_VERSION}/cabal/opengl-register.sh:${PORTSDIR}/x11-toolkits/hs-opengl-ghc

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
SUBDIR=		${PORTNAME}${PKGNAMESUFFIX}

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure --ghc --prefix=${PREFIX} --libdir=${CABALDIR} \
	 --libsubdir='' --datasubdir=''

do-build:
	cd ${WRKSRC} && ${CABALCMD} build \
	 && ${CABALCMD} --gen-script register

do-install:
	cd ${WRKSRC} && ${CABALCMD} install \
	 && ${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.post.mk>
