# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.19.6
CATEGORIES=	textproc haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/HaXml/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
DISTNAME=	HaXml-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A collection of utilities for using Haskell and XML together

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-polyparse-ghc>=1.1:${PORTSDIR}/textproc/hs-polyparse-ghc
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-polyparse-ghc>=1.1:${PORTSDIR}/textproc/hs-polyparse-ghc

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX}

GHC_VERSION=	6.8.3
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION} \
		HAXMLDIR=lib/HaXml-${PORTVERSION} \
		GHCDIR=ghc-${GHC_VERSION} \
		SUBDIR=lib/HaXml-${PORTVERSION}/ghc-${GHC_VERSION} \
		PORTVERSION=${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/HaXml-${PORTVERSION}
PORTDOCS=	*

.if !defined(NOPORTDOCS)
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

do-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/runhaskell Setup.hs configure ${CONFIGURE_ARGS}

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/runhaskell Setup.hs build

do-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/runhaskell Setup.hs install

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dist/installed-pkg-config ${PREFIX}/lib/HaXml-${PORTVERSION}/ghc-${GHC_VERSION}/HaXml.pkgconf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${CP} -R docs/ ${DOCSDIR})
.endif

.include <bsd.port.mk>
