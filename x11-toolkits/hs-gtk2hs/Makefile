# New ports collection makefile for:   gtk2hs
# Date created:        03 June 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk2hs
PORTVERSION=	0.10.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GTK2 Binding for Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		xulrunner:${PORTSDIR}/www/xulrunner \
		gstreamer-plugins>=0.10:${PORTSDIR}/multimedia/gstreamer-plugins
LIB_DEPENDS=	gstreamer-0.10:${PORTSDIR}/multimedia/gstreamer \
		gtkglext-x11-1.0:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomelibs gtk20 libglade2 gtksourceview2 gconf2 librsvg2 gnomevfs2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
SUB_FILES=	pkg-install
PKGDEINSTALL=	${PKGINSTALL}

GHC_VERSION=	6.8.3
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"
SUB_LIST+=	GHC_VERSION="${GHC_VERSION}" \
		PORTVERSION=${PORTVERSION} \
		PKGS="${PKGS}"

PKGS=		glib gio gtk glade cairo svgcairo gtkglext gconf \
		gtksourceview2 mozembed soegtk gstreamer \
		gnomevfs

.include <bsd.port.mk>
