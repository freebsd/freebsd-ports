# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vinagre
PORTVERSION=	3.18.2
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgtk-vnc-2.0.so:${PORTSDIR}/net/gtk-vnc \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome pathfix pkgconfig \
		shared-mime-info tar:xz
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
AVAHI_LIB_DEPENDS=	libavahi-ui-gtk3.so:${PORTSDIR}/net/avahi-gtk3
SPICE_DESC=	SPICE protocol support
SPICE_CONFIGURE_ENABLE=	spice
SPICE_BUILD_DEPENDS=	spice-gtk>=0.30_1:${PORTSDIR}/deskutils/spice-gtk
SPICE_LIB_DEPENDS=	libspice-client-gtk-3.0.so:${PORTSDIR}/deskutils/spice-gtk
TELEPATHY_DESC=	Telepathy integration
TELEPATHY_CONFIGURE_WITH=	telepathy
TELEPATHY_LIB_DEPENDS=	libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib \
			libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RDP_DESC=	MS Windows remote desktop support
RDP_CONFIGURE_ENABLE=	rdp
RDP_BUILD_DEPENDS=	xfreerdp:${PORTSDIR}/net/freerdp
RDP_RUN_DEPENDS=	xfreerdp:${PORTSDIR}/net/freerdp

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
