# New ports collection makefile for:	hs-digest-ghc
# Date created:				January 22, 2009
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	digest
PORTVERSION=	0.0.0.5
CATEGORIES=	security haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Efficient cryptographic hash implementations in Haskell

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc

GHC_VERSION=	6.8.3
CABALCMD=	${LOCALBASE}/bin/runghc Setup.hs
CABALDIR=	lib/ghc-${GHC_VERSION}/cabal

SUBDIR=		lib/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	GHC_VERSION=${GHC_VERSION}		\
		PORTNAME=${PORTNAME}			\
		PORTVERSION=${PORTVERSION}		\
		SUBDIR=${CABALDIR}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE html

CONFIGURE_ARGS=	--ghc --prefix=${PREFIX} --libdir=${PREFIX}/${CABALDIR} --libsubdir='' --datasubdir=''

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
PLIST_SUB+=	RMLIC="@comment "
.else
PLIST_SUB+=	RMLIC=""
.endif

do-configure:
	cd ${WRKSRC} && ${CABALCMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${CABALCMD} build && ${CABALCMD} --gen-script register
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${CABALCMD} haddock
.endif

do-install:
	cd ${WRKSRC} && ${CABALCMD} install
	${INSTALL_SCRIPT} ${WRKSRC}/register.sh ${PREFIX}/${CABALDIR}/${PORTNAME}-register.sh

.include <bsd.port.mk>
