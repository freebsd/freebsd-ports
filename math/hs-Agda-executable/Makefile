# New ports collection makefile for: hs-Agda-executable
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda-executable
PORTVERSION=	2.2.6
CATEGORIES=	math haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Command-line program for type-checking and compiling Agda programs

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-Agda>=2.2.6:${PORTSDIR}/math/hs-Agda
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-Agda>=2.2.6:${PORTSDIR}/math/hs-Agda

LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

USE_ICONV=	yes

GHC_VERSION=		6.10.4
AGDAEXECUTABLE_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=			${PREFIX}/share/doc/${DISTNAME}
AGDAEXECUTABLE_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		AGDAEXECUTABLE_VERSION=${AGDAEXECUTABLE_VERSION} \
		AGDAEXECUTABLE_LIBDIR_REL=${AGDAEXECUTABLE_LIBDIR_REL}

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source --executables \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install

.include <bsd.port.mk>
