# New ports collection makefile for: hs-Agda
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Agda
PORTVERSION=	2.2.6
CATEGORIES=	math haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A functional programming language and proof assistant

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-QuickCheck>=2.1.0.2:${PORTSDIR}/devel/hs-QuickCheck \
		hs-binary-ghc>=0.4.4:${PORTSDIR}/devel/hs-binary-ghc \
		hs-zlib>=0.4.0.1:${PORTSDIR}/archivers/hs-zlib \
		hs-haskeline>=0.3:${PORTSDIR}/devel/hs-haskeline \
		hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-happy>=1.15:${PORTSDIR}/devel/hs-happy \
		hs-alex>=2.0.1:${PORTSDIR}/devel/hs-alex
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-QuickCheck>=2.1.0.2:${PORTSDIR}/devel/hs-QuickCheck \
		hs-binary-ghc>=0.4.4:${PORTSDIR}/devel/hs-binary-ghc \
		hs-zlib>=0.4.0.1:${PORTSDIR}/archivers/hs-zlib \
		hs-haskeline>=0.3:${PORTSDIR}/devel/hs-haskeline \
		hs-utf8-string-ghc>=0.1:${PORTSDIR}/devel/hs-utf8-string-ghc

LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

USE_ICONV=	yes

GHC_VERSION=	6.10.4
AGDA_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DATADIR=		${PREFIX}/share/${DISTNAME}
PORTDATA=	*

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
AGDA_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		AGDA_VERSION=${AGDA_VERSION} \
		AGDA_LIBDIR_REL=${AGDA_LIBDIR_REL}

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
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal
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
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source --executables \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${AGDA_LIBDIR_REL}/register.sh
.if !defined(NOPORTDATA)
	cd ${WRKSRC} && ${INSTALL_DATA} README ${DATADIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DATADIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "================================================================="
	@${CAT}      "${PKGMESSAGE}"
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG}

.include <bsd.port.mk>
