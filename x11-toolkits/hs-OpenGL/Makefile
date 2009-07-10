# New ports collection makefile for:	hs-opengl-ghc
# Date created:				2008-09-04
# Whom:					Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	opengl
PORTVERSION=	2.2.1.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${GHC_VERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc
DISTNAME=	ghc-${GHC_VERSION}-src-extralibs

#PATCH_SITES=	http://lambda.foldr.org/~vs/FreeBSD/ghc-cabal-${GHC_VERSION}/
#PATCHFILES=	patch-cabal-${GHC_VERSION}-Setup.hs

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	OpenGL bindings for Haskell programs

USE_BZIP2=	yes
USE_GL=		yes
USE_XORG=	x11 xt

GHC_VERSION=	6.8.3
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		PORTVERSION=${PORTVERSION} \
		PORTNAME=${PORTNAME} \
		SUBDIR=lib/ghc-${GHC_VERSION}/cabal

.include <bsd.port.pre.mk>

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc

# 'owned' by lang/ghc:
CABALDIR=	${PREFIX}/lib/ghc-${GHC_VERSION}/cabal
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
SUBDIR=		${PORTNAME}${PKGNAMESUFFIX}

WRKSRC=${WRKDIR}/ghc-${GHC_VERSION}/libraries/OpenGL

post-patch:
	@${REINPLACE_CMD} 's|/usr/local/include|${LOCALBASE}/include|g' \
		${WRKSRC}/configure

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
