# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.07b
PORTREVISION=	0
CATEGORIES=	textproc haskell
MASTER_SITES=	http://www.haskell.org/HaXml/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/HaXml/
DISTNAME=	HaXml-${PORTVERSION}
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

.if !defined(WITHOUT_NHC98)
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.else
WITH_GHC=	yes
BUILD_DEPENDS=	hmake:${PORTSDIR}/devel/hs-hmake
.endif
.if defined(WITH_GHC)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	#empty

CONFIGURE_ARGS+=	--prefix=${PREFIX}

.if !defined(WITHOUT_NHC98) && !defined(WITH_GHC)
CONFIGURE_ARGS+=	--buildwith=nhc98
.elif defined(WITHOUT_NHC98)
CONFIGURE_ARGS+=	--buildwith=ghc
.endif

.if !defined(WITHOUT_NHC98)
PLIST_SUB+=	NHC98=""
.else
PLIST_SUB+=	NHC98="@comment "
.endif
.if defined(WITH_GHC)
GHC_VERSION=	`${PREFIX}/bin/ghc --version 2>&1 | \
			${SED} 's/^.*version[ ]*\([0-9.]*\).*/\1/'`
PLIST_SUB+=	GHC="" GHC_VERSION="${GHC_VERSION}"
.else
PLIST_SUB+=	GHC="@comment "
.endif

pre-everything:
	@${ECHO_CMD} ""
.if defined(WITH_GHC) && !defined(WITHOUT_NHC98)
	@${ECHO_CMD} " HaXml will be installed for both nhc98 and ghc."
.elif defined(WITHOUT_NHC98)
	@${ECHO_CMD} " HaXml will be installed for ghc only."
.else
	@${ECHO_CMD} " HaXml will be installed for nhc98 only."
	@${ECHO_CMD} " Define WITH_GHC      to install for ghc, too."
	@${ECHO_CMD} " Define WITHOUT_NHC98 to install for ghc only."
.endif
	@${ECHO_CMD} ""

post-install:
.if defined(WITH_GHC)
	@${INSTALL_DATA} ${WRKSRC}/obj/ghc/pkg.conf \
		${PREFIX}/lib/ghc-${GHC_VERSION}/imports/HaXml/
.endif
	@(cd ${WRKSRC} && ${INSTALL_PROGRAM} \
		Canonicalise DtdToHaskell MkOneOf Validate Xtract ${PREFIX}/bin)
.if !defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/docs/CVS
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${CP} -R docs/* ${DOCSDIR})
.endif

.include <bsd.port.mk>
