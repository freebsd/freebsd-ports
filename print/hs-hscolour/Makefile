# New ports collection makefile for: hs-hscolour
# Date created:        February 22 2008
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hscolour
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	print haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/contrib/ \
		http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	Colourise Haskell code

LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4

.if !defined(SLAVE)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.else
NO_PKG_REGISTER=
.endif

GHC_VERSION=	6.8.3
HSCOLOUR_VERSION=	${PORTVERSION}

CABAL_CMD=	runghc Setup.hs

DATADIR=		${PREFIX}/share/${DISTNAME}
HSCOLOUR_LIBDIR_REL=	lib/${DISTNAME}
DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HSCOLOUR_LIBDIR_REL=${HSCOLOUR_LIBDIR_REL} \
		HSCOLOUR_VERSION=${HSCOLOUR_VERSION} \

.SILENT:

do-configure:
	cd ${WRKSRC} && ${CABAL_CMD} configure --ghc --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${CABAL_CMD} build
.if !defined(SLAVE)
	cd ${WRKSRC} && ${CABAL_CMD} register --gen-script
.endif

do-install:
	cd ${WRKSRC} && ${CABAL_CMD} install

post-install:
	${STRIP_CMD} ${PREFIX}/bin/HsColour
.if !defined(SLAVE)
	cd ${WRKSRC} && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HSCOLOUR_LIBDIR_REL}/register.sh  && \
		${INSTALL_DATA} README ${DOCSDIR}/README
.endif
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
