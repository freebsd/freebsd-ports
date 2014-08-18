# Created by: ade, archie
# $FreeBSD$
#   $MCom: ports/trunk/x11-fm/nautilus/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	nautilus
PORTVERSION=	3.12.2
PORTREVISION=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	File manager for the GNOME desktop

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig shared-mime-info tar:xz
USE_GNOME=	gnomeprefix intlhack gnomedesktop3 libxml2 \
		gvfs introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="-pthread"
CONFIGURE_ARGS=	--disable-packagekit
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.nautilus.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	TRACKER
OPTIONS_DEFAULT=TRACKER
TRACKER_DESC=	Tracker support
TRACKER_LIB_DEPENDS=	libtracker-control-1.0.so:${PORTSDIR}/sysutils/tracker
TRACKER_CONFIGURE_ENABLE=	tracker

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
