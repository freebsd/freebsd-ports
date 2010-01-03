# New ports collection makefile for: hs-oeis
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	oeis
PORTVERSION=	0.2.2
CATEGORIES=	www haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell interface to the Online Encyclopedia of Integer Sequences

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-HTTP>=4000.0.2:${PORTSDIR}/www/hs-HTTP
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-HTTP>=4000.0.2:${PORTSDIR}/www/hs-HTTP

GHC_VERSION=	6.10.4
OEIS_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=		${PREFIX}/share/${DISTNAME}
PORTDATA=	*

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
OEIS_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		OEIS_VERSION=${OEIS_VERSION} \
		OEIS_LIBDIR_REL=${OEIS_LIBDIR_REL}

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.lhs -o setup -package Cabal
.if !defined(NOPORTDATA)
	cd ${WRKSRC} && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}
.else
	cd ${WRKSRC} && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX} \
	    --datadir='' --datasubdir='' --docdir='${DOCSDIR}'
.endif

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${OEIS_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
