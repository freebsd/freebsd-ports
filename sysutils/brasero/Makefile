PORTNAME=	brasero
PORTVERSION=	3.12.3
PORTREVISION=	8
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop
WWW=		https://projects.gnome.org/brasero/

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libtotem-plparser.so:multimedia/totem-pl-parser \
		libcanberra-gtk3.so:audio/libcanberra-gtk3
RUN_DEPENDS=	growisofs:sysutils/dvd+rw-tools \
		cdrdao:sysutils/cdrdao

USES=		desktop-file-utils gettext gmake gnome gstreamer libtool pathfix \
		pkgconfig shared-mime-info tar:xz xorg
USE_GNOME=	cairo gdkpixbuf gnomeprefix gtk30 intlhack \
		introspection:build libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_XORG=	sm ice
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-inotify --enable-search=no --enable-playlist=no \
		--enable-introspection=yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1 -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.brasero.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LIBBURNIA

LIBBURNIA_DESC=	Build libburnia plug-ins

LIBBURNIA_LIB_DEPENDS=	libburn.so:devel/libburn \
			libisofs.so:devel/libisofs
LIBBURNIA_CONFIGURE_ENABLE=	libburnia

PLIST_SUB=	FULL_VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/libbrasero-burn/burn-process.c

.include <bsd.port.mk>
