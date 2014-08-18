# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/sysutils/brasero/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	brasero
PORTVERSION=	3.11.3
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libtotem-plparser.so:${PORTSDIR}/multimedia/totem-pl-parser \
		libcanberra-gtk3.so:${PORTSDIR}/audio/libcanberra-gtk3
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao

USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
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

OPTIONS_DEFINE=	NAUTILUS LIBBURNIA
OPTIONS_DEFAULT=NAUTILUS
NAUTILUS_DESC=	Build nautilus extension
LIBBURNIA_DESC=	Build libburnia plug-ins

PLIST_SUB=	FULL_VERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNAUTILUS}
USE_GNOME+=	nautilus3
CONFIGURE_ARGS+=--enable-nautilus
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--enable-nautilus=no
.endif

.if ${PORT_OPTIONS:MLIBBURNIA}
LIB_DEPENDS+=	libburn.so:${PORTSDIR}/devel/libburn \
		libisofs.so:${PORTSDIR}/devel/libisofs
CONFIGURE_ARGS+=--enable-libburnia
PLIST_SUB+=	LIBBURNIA=""
.else
CONFIGURE_ARGS+=--disable-libburnia
PLIST_SUB+=	LIBBURNIA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/libbrasero-burn/burn-process.c

.include <bsd.port.mk>
