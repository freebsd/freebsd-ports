# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	textproc haskell
MASTER_SITES=	http://www.haskell.org/HaXml/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/HaXml/
PKGNAMEPREFIX=	hs-
DISTNAME=	HaXml-${PORTVERSION}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A collection of utilities for using Haskell and XML together

USE_SIZE=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}/bin

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/nhc98)
WITH_NHC98=	yes
.endif
.if exists(${LOCALBASE}/bin/ghc)
WITH_GHC=	yes
.endif
.if exists(${LOCALBASE}/bin/hugs)
WITH_HUGS=	yes
.endif

.if defined(PACKAGE_BUILDING)
WITH_NHC98=	yes
WITH_GHC=	yes
WITH_HUGS=	yes
.endif

.if defined(WITH_NHC98)
BUILD_DEPENDS+=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.endif
.if defined(WITH_GHC)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif
.if defined(WITH_HUGS)
BUILD_DEPENDS+=	hugs:${PORTSDIR}/lang/hugs
RUN_DEPENDS+=	hugs:${PORTSDIR}/lang/hugs
.endif

.if defined(WITH_NHC98)
PLIST_SUB+=	NHC98=""
.else
PLIST_SUB+=	NHC98="@comment "
.endif
.if defined(WITH_GHC)
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC="" GHC_VERSION="${GHC_VERSION}"
.else
PLIST_SUB+=	GHC="@comment "
.endif
.if defined(WITH_HUGS)
PLIST_SUB+=	HUGS=""
.else
PLIST_SUB+=	HUGS="@comment "
.endif

pre-everything::
	@${ECHO_CMD} ""
.if defined(WITH_NHC98)
	@${ECHO_CMD} " HaXml will be installed for nhc98."
.else
	@${ECHO_CMD} " Define WITH_NHC98 to install HaXml for nhc98."
.endif
.if defined(WITH_GHC)
	@${ECHO_CMD} " HaXml will be installed for ghc."
.else
	@${ECHO_CMD} " Define WITH_GHC   to install HaXml for ghc."
.endif
.if defined(WITH_HUGS)
	@${ECHO_CMD} " HaXml will be installed for hugs"
.else
	@${ECHO_CMD} " Define WITH_HUGS  to install HaXml for hugs"
.endif
.if !defined(WITH_GHC) && !defined(WITH_NHC98) && !defined(WITH_HUGS)
	@${FALSE}
.endif
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/false,/usr/bin/false,' ${WRKSRC}/configure

post-install:
.if defined(WITH_GHC)
	@${INSTALL_DATA} ${WRKSRC}/obj/ghc/pkg.conf \
		${PREFIX}/lib/ghc-${GHC_VERSION}/imports/HaXml/
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${CP} -R docs/* ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
