# New ports collection makefile for:	bytestring-csv
# Date created:				November 25, 2008
# Whom:					Samy Al Bahra <sbahra@kerneled.org>
#
# $FreeBSD$

PORTNAME=	bytestring-csv
PORTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	textproc haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/ \
		http://carte.kerneled.org/mirror/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parse CSV formatted data efficiently with Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-dlist>=0.4.1:${PORTSDIR}/devel/hs-dlist
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-dlist>=0.4.1:${PORTSDIR}/devel/hs-dlist

GHC_VERSION=		6.10.4
BYTESTRINGCSV_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
BYTESTRINGCSV_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		BYTESTRINGCSV_VERSION=${BYTESTRINGCSV_VERSION} \
		BYTESTRINGCSV_LIBDIR_REL=${BYTESTRINGCSV_LIBDIR_REL}

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

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.lhs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${BYTESTRINGCSV_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
