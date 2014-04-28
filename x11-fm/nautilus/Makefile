# Created by: ade, archie
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11-fm/nautilus/Makefile 19340 2014-03-25 20:57:54Z gusi $

PORTNAME=	nautilus
PORTVERSION=	3.12.0
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:${PORTSDIR}/misc/gnome-icon-theme \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig shared-mime-info tar:xz
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		gvfs introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--disable-packagekit

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=TRACKER
TRACKER_DESC=	Tracker support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTRACKER}
LIB_DEPENDS+=	libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker
CONFIGURE_ARGS+=--enable-tracker=yes
PLIST_SUB+=	TRACKER=""
.else
CONFIGURE_ARGS+=--enable-tracker=no
PLIST_SUB+=	TRACKER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libnautilus-extension.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/nautilus/extensions-3.0/libnautilus-sendto.so

.include <bsd.port.mk>
