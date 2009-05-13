# New ports collection makefile for:	porte
# Date created:				November 4, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	porte
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	ports-mgmt haskell
MASTER_SITES=	http://carte.repnop.org/releases/

MAINTAINER=	sbahra@kerneled.org
COMMENT=	FreeBSD ports index search and statistical analysis tool

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc					\
		hs-stringsearch>=0.2.1.1:${PORTSDIR}/textproc/hs-stringsearch
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

CABAL=		${LOCALBASE}/bin/runghc Setup.hs
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
