# Created by: ade, archie
# $FreeBSD$

PORTNAME=	mate-file-manager
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd:${PORTSDIR}/devel/gvfs

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_MATE=	desktop icontheme:run
USE_XORG=	ice x11 xrender
USE_GNOME=	glib20 gnomehier gtk20 intlhack introspection:build \
		libxml2 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--enable-static \
		--disable-packagekit \
		--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

.include <bsd.port.mk>
