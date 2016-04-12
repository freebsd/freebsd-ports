# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brasero
PORTVERSION=	3.12.1
PORTREVISION=	1
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libcanberra-gtk3.so:audio/libcanberra-gtk3
RUN_DEPENDS=	growisofs:sysutils/dvd+rw-tools \
		cdrdao:sysutils/cdrdao

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info tar:xz
USE_GNOME=	gnomeprefix gtk30 intlhack libxml2
GNU_CONFIGURE=	yes
USE_XORG=	sm ice
USE_LDCONFIG=	yes
USE_GSTREAMER1=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --enable-search=no --enable-playlist=no \
		--enable-introspection=yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1 -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.brasero.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	NAUTILUS LIBBURNIA
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Build nautilus extension
LIBBURNIA_DESC=	Build libburnia plug-ins
NAUTILUS_USE=	GNOME=nautilus3
NAUTILUS_CONFIGURE_ENABLE=	nautilus
LIBBURNIA_LIB_DEPENDS=	libburn.so:devel/libburn \
			libisofs.so:devel/libisofs
LIBBURNIA_CONFIGURE_ENABLE=	libburnia

PLIST_SUB=	FULL_VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/libbrasero-burn/burn-process.c

.include <bsd.port.mk>
