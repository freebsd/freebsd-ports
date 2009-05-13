# New ports collection makefile for:	bytestring-csv
# Date created:				November 25, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	bytestring-csv
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	textproc haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/ \
		http://carte.kerneled.org/mirror/
PKGNAMEPREFIX=	hs-

MAINTAINER=	sbahra@kerneled.org
COMMENT=	Parse CSV formatted data efficiently with Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc		\
		hs-dlist>=0.4.1:${PORTSDIR}/devel/hs-dlist
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CABAL=		${LOCALBASE}/bin/runghc Setup.lhs
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	GHC_VERSION="${GHC_VERSION}"		\
		PORTVERSION=${PORTVERSION}		\
		SUBDIR=${SUBDIR}

do-configure:
	cd ${WRKSRC} && ${CABAL} configure --prefix=${PREFIX} --ghc

do-build:
	cd ${WRKSRC} && ${CABAL} build && ${CABAL} register --gen-script

do-install:
	cd ${WRKSRC} && ${CABAL} install
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${SUBDIR}/register.sh

.include <bsd.port.mk>
