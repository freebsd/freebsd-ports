# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	textproc haskell
MASTER_SITES=	http://www.haskell.org/HaXml/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/HaXml/
PKGNAMEPREFIX=	hs-
DISTNAME=	HaXml-${PORTVERSION}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A collection of utilities for using Haskell and XML together

.if !defined(WITHOUT_NHC98)
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.endif
.if !defined(WITHOUT_GHC)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	#empty

CONFIGURE_ARGS+=	--prefix=${PREFIX}/bin

.if defined(WITHOUT_GHC)
CONFIGURE_ARGS+=	--buildwith=nhc98
.endif
.if defined(WITHOUT_NHC98)
CONFIGURE_ARGS+=	--buildwith=ghc
.endif

.if !defined(WITHOUT_NHC98)
PLIST_SUB+=	NHC98=""
.else
PLIST_SUB+=	NHC98="@comment "
.endif
.if !defined(WITHOUT_GHC)
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC="" GHC_VERSION="${GHC_VERSION}"
.else
PLIST_SUB+=	GHC="@comment "
.endif

pre-everything::
	@${ECHO_CMD} ""
.if defined(WITHOUT_GHC) && defined(WITHOUT_NHC98)
	@${ECHO_CMD} "Without everything?"
	@${ECHO_CMD} ""
	@${FALSE}
.elif !defined(WITHOUT_GHC) && !defined(WITHOUT_NHC98)
	@${ECHO_CMD} " HaXml will be installed for both nhc98 and ghc."
	@${ECHO_CMD} " Define WITHOUT_GHC   to avoid installation for ghc."
	@${ECHO_CMD} " Define WITHOUT_NHC98 to avoid installation for nhc98."
.elif defined(WITHOUT_NHC98)
	@${ECHO_CMD} " HaXml will be installed for ghc only."
.elif defined(WITHOUT_GHC)
	@${ECHO_CMD} " HaXml will be installed for nhc98 only."
.endif
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/false,/usr/bin/false,' ${WRKSRC}/configure

post-install:
.if !defined(WITHOUT_GHC)
	@${INSTALL_DATA} ${WRKSRC}/obj/ghc/pkg.conf \
		${PREFIX}/lib/ghc-${GHC_VERSION}/imports/HaXml/
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.endif
.if !defined(NOPORTDOCS)
	@${RM} -rf ${WRKSRC}/docs/CVS
	@${RM} -rf ${WRKSRC}/docs/HaXml/CVS
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${CP} -R docs/* ${DOCSDIR})
.endif

.include <bsd.port.mk>
