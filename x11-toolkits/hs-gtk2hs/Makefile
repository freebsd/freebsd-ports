# New ports collection makefile for:   gtk2hs
# Date created:        03 June 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk2hs
PORTVERSION=	0.9.13
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GTK2 Binding for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		xulrunner:${PORTSDIR}/www/xulrunner
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gtk20 libglade2 gtksourceview gconf2 librsvg2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
SUB_FILES=	pkg-install
PKGDEINSTALL=	${PKGINSTALL}

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"
SUB_LIST+=	GHC_VERSION="${GHC_VERSION}" \
		PORTVERSION=${PORTVERSION} \
		PKGS="${PKGS}"

PKGS=		glib cairo gtk glade gconf sourceview mozembed soegtk svgcairo gnomevfs

.include <bsd.port.mk>
