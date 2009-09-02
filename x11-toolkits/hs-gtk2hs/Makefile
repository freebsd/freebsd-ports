# New ports collection makefile for:   gtk2hs
# Date created:        03 June 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk2hs
PORTVERSION=	0.10.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	SF
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

GHC_VERSION=	6.10.4
GTK2HS_VERSION=	${PORTVERSION}

GTK2HS_LIBDIR_REL=	lib/${PORTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		GTK2HS_VERSION=${GTK2HS_VERSION} \
		GTK2HS_LIBDIR_REL=${GTK2HS_LIBDIR_REL}

SUB_LIST+=	GHC_VERSION="${GHC_VERSION}" \
		PORTVERSION=${PORTVERSION} \
		PKGS="${PKGS}"

PKGS=		glib cairo gstreamer gnomevfs gio \
		gtk glade svgcairo gtkglext gconf \
		gtksourceview2 mozembed soegtk

CONFIGURE_ENV+=	GIO_CFLAGS="-I${LOCALBASE}/include/gio-unix-2.0"

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

CONFIGURE_ARGS+=	--enable-docs

PORTDOCS=	*
.endif

post-install:
.if defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.endif
	@${INSTALL_DATA} ${WRKSRC}/docs/prologue.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING.GPLv3 ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING.LGPLv3 ${DOCSDIR}

.include <bsd.port.mk>
