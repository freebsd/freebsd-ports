# New ports collection makefile for: hs-hscolour-docs
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hscolour-docs
PORTVERSION=	1.12
CATEGORIES=	print haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/contrib/ \
		http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
DISTNAME=	hscolour-${PORTVERSION}

MAINTAINER=	jacula@gmail.com
COMMENT=	Documentation for HsColour

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		haddock:${PORTSDIR}/devel/hs-haddock \
		HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	${PORTVERSION}
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

CABAL_CMD=	runghc Setup.hs

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}

.SILENT:

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} haddock --executables --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css

do-install:
	${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC}/dist/doc/html/hscolour && ${COPYTREE_SHARE} \* ${DOCSDIR}/html

.include <bsd.port.mk>
