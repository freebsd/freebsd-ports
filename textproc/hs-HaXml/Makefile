# New ports collection makefile for:	HaXml
# Date created:				01 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	haxml
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	textproc haskell
MASTER_SITES=	http://www.haskell.org/HaXml/ \
		ftp://ftp.cs.york.ac.uk/pub/haskell/HaXml/
PKGNAMEPREFIX=	hs-
DISTNAME=	HaXml-${PORTVERSION}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A collection of utilities for using Haskell and XML together

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}/bin

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/false,/usr/bin/false,' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e '/hugs/d' ${WRKSRC}/obj/compilers
	@${REINPLACE_CMD} -e '/nhc98/d' ${WRKSRC}/obj/compilers

post-install:
	@${INSTALL_DATA} ${WRKSRC}/obj/ghc/HaXml.pkgconf \
		${PREFIX}/lib/ghc-${GHC_VERSION}/imports/HaXml/
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} && ${RM} -rf docs/HaXml/CVS)
	@(cd ${WRKSRC} && ${CP} -R docs/* ${DOCSDIR})
.endif

.include <bsd.port.mk>
