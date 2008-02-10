# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.13.3
CATEGORIES=	textproc haskell
MASTER_SITES=	http://www.haskell.org/HaXml/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/HaXml/
PKGNAMEPREFIX=	hs-
DISTNAME=	HaXml-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A collection of utilities for using Haskell and XML together

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc

CONFIGURE_ARGS+=	--prefix=${PREFIX}

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}" \
		HAXML_VERSION=${PORTVERSION}
PORTDOCS=	*

do-configure:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/runhaskell Setup.hs configure ${CONFIGURE_ARGS}

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/runhaskell Setup.hs build

do-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/runhaskell Setup.hs install

post-install:
	@${INSTALL_DATA} ${WRKSRC}/dist/installed-pkg-config ${PREFIX}/lib/HaXml-${PORTVERSION}/ghc-${GHC_VERSION}/HaXml.pkgconf
	@${RM} -f ${LOCALBASE}/lib/ghc-${GHC_VERSION}/package.conf.old
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${CP} -R docs/* ${DOCSDIR})
.endif

.include <bsd.port.mk>
