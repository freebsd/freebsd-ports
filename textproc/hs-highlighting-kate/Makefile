# New ports collection makefile for:	highlighting-kate
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlighting-kate
PORTVERSION=	0.2.4
CATEGORIES=	textproc haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell syntax highlighting library for 50+ languages

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-pcre-light-ghc>=0.3:${PORTSDIR}/devel/hs-pcre-light-ghc
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-pcre-light-ghc>=0.3:${PORTSDIR}/devel/hs-pcre-light-ghc

GHC_VERSION=	6.8.3
CABALCMD=	${LOCALBASE}/bin/runghc Setup.lhs
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
