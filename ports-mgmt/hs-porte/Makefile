# New ports collection makefile for:	porte
# Date created:				November 4, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	porte
PORTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	ports-mgmt haskell
MASTER_SITES=	http://carte.repnop.org/releases/

MAINTAINER=	sbahra@kerneled.org
COMMENT=	FreeBSD ports index search and statistical analysis tool

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-stringsearch>=0.2.1.1:${PORTSDIR}/textproc/hs-stringsearch
BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-stringsearch>=0.2.1.1:${PORTSDIR}/textproc/hs-stringsearch
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

GHC_VERSION=	6.10.4
PORTE_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=	${PREFIX}/share/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
PORTE_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		PORTE_VERSION=${PORTE_VERSION} \
		PORTE_LIBDIR_REL=${PORTE_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif

BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour
HSCOLOUR_VERSION=	1.13
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source --executables \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${PORTE_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
