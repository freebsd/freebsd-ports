# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vinagre
PORTVERSION=	3.18.2
PORTREVISION=	5
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	appstream-glib>=0:devel/appstream-glib \
		itstool:textproc/itstool \
		gnome-autogen.sh:devel/gnome-common \
		yelp-tools>=0:textproc/yelp-tools
LIB_DEPENDS=	libgtk-vnc-2.0.so:net/gtk-vnc \
		libgdbm.so:databases/gdbm \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gnome-icon-theme>=0:misc/gnome-icon-theme

PORTSCOUT=	limitw:1,even

USES=		autoreconf desktop-file-utils gettext gmake gnome pathfix \
		pkgconfig shared-mime-info tar:xz
USE_GNOME=	gtk30 intlhack libxml2 vte3
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-ssh
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.Vinagre.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	AVAHI SPICE TELEPATHY RDP DOCS
OPTIONS_DEFAULT=AVAHI SPICE TELEPATHY RDP
AVAHI_CONFIGURE_WITH=	avahi
AVAHI_LIB_DEPENDS=	libavahi-ui-gtk3.so:net/avahi-gtk3
SPICE_DESC=	SPICE protocol support
SPICE_CONFIGURE_ENABLE=	spice
SPICE_BUILD_DEPENDS=	spice-gtk>=0.30_1:deskutils/spice-gtk
SPICE_LIB_DEPENDS=	libspice-client-gtk-3.0.so:deskutils/spice-gtk
TELEPATHY_DESC=	Telepathy integration
TELEPATHY_CONFIGURE_WITH=	telepathy
TELEPATHY_LIB_DEPENDS=	libtelepathy-glib.so:net-im/telepathy-glib \
			libdbus-glib-1.so:devel/dbus-glib
RDP_DESC=	MS Windows remote desktop support
RDP_CONFIGURE_ENABLE=	rdp
RDP_BUILD_DEPENDS=	xfreerdp:net/freerdp
RDP_RUN_DEPENDS=	xfreerdp:net/freerdp

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
