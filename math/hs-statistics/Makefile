# New ports collection makefile for: hs-statistics
# Date created:        January 03 2010
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	statistics
PORTVERSION=	0.4.1
CATEGORIES=	math haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell library of statistical types, data, and functions

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-uvector>=0.1.0.4:${PORTSDIR}/devel/hs-uvector \
		hs-uvector-algorithms>=0.2:${PORTSDIR}/devel/hs-uvector-algorithms \
		hs-erf>=1.0.0.0:${PORTSDIR}/math/hs-erf \
		hs-mwc-random>=0.4.1.1:${PORTSDIR}/math/hs-mwc-random
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-uvector>=0.1.0.4:${PORTSDIR}/devel/hs-uvector \
		hs-uvector-algorithms>=0.2:${PORTSDIR}/devel/hs-uvector-algorithms \
		hs-erf>=1.0.0.0:${PORTSDIR}/math/hs-erf \
		hs-mwc-random>=0.4.1.1:${PORTSDIR}/math/hs-mwc-random

GHC_VERSION=		6.10.4
STATISTICS_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=		${PREFIX}/share/${DISTNAME}
PORTDATA=	*

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
STATISTICS_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		STATISTICS_VERSION=${STATISTICS_VERSION} \
		STATISTICS_LIBDIR_REL=${STATISTICS_LIBDIR_REL}

.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS=""
.else
PLIST_SUB+=	NOPORTDOCS="@comment "
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
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${STATISTICS_LIBDIR_REL}/register.sh
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR} && ${INSTALL_DATA} ${WRKSRC}/README ${DATADIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
