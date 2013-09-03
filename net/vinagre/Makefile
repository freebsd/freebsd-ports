# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/vinagre/Makefile,v 1.48 2012/09/01 23:02:11 mezz Exp $

PORTNAME=	vinagre
PORTVERSION=	2.30.3
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC client for the GNOME Desktop

LIB_DEPENDS=	gtk-vnc-1.0:${PORTSDIR}/net/gtk-vnc \
    		avahi-core:${PORTSDIR}/net/avahi-app \
		avahi-ui:${PORTSDIR}/net/avahi-gtk \
		gdbm:${PORTSDIR}/databases/gdbm \
		gnome-keyring:${PORTSDIR}/security/libgnome-keyring

CONFLICTS=	vinagre-3.[0-9]*

USE_BZIP2=	yes
USES=		pathfix gettext gmake pkgconfig
USE_GNOME=	gnomeprefix intlhack vte gconf2 gnomedocutils gnomepanel
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-avahi --enable-applet -enable-ssh
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	vinagre.schemas

MAN1=		vinagre.1

OPTIONS_DEFINE=	TELEPATHY
OPTIONS_DEFAULT=TELEPATHY
TELEPATHY_DESC=	Telepathy integration

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTELEPATHY}
CONFIGURE_ARGS+=--enable-telepathy
LIB_DEPENDS+=	telepathy-glib:${PORTSDIR}/net-im/telepathy-glib
PLIST_SUB+=	TELEPATHY=""
.else
CONFIGURE_ARGS+=--disable-telepathy
PLIST_SUB+=	TELEPATHY="@comment "
.endif

post-install:
	@-update-desktop-database > /dev/null
	@-update-mime-database ${PREFIX}/share/mime > /dev/null
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog MAINTAINERS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
