# New ports collection makefile for:	gio
# Date created:         		2004-03-09
# Whom:					obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gio
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	htoolkit
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A 'middle-ground' GUI library for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		${LOCALBASE}/share/port/port.pkg:${PORTSDIR}/x11-toolkits/hs-port
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		${LOCALBASE}/share/port/port.pkg:${PORTSDIR}/x11-toolkits/hs-port

USE_BZIP2=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ENV+=	DOCSDIR="${DOCSDIR}" INSTALL_DATA="${INSTALL_DATA}"
ALL_TARGET=	release

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock \
		${LOCALBASE}/share/doc/ghc6/index.html:${PORTSDIR}/lang/ghc6-doc
CONFIGURE_ARGS+=	-haddock-libs ${LOCALBASE}/share/doc/ghc6/libraries/base \
			-haddock-html ${LOCALBASE}/share/doc/ghc6/libraries/
ALL_TARGET=	release doc
INSTALL_TARGET=	install install-doc
.endif

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config/gio.pkg ${DATADIR}

.include <bsd.port.mk>
