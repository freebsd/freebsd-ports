# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/seahorse/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	seahorse
PORTVERSION=	3.12.2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		valac:${PORTSDIR}/lang/vala \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

USE_XORG=	sm
USE_LDCONFIG=	yes
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	intlhack gnomeprefix gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP NOTIFY AVAHI
OPTIONS_DEFAULT=LDAP NOTIFY AVAHI
LDAP_CONFIGURE_ENABLE=	ldap
LDAP_USE=	OPENLDAP=yes
NOTIFY_CONFIGURE_ENABLE=	libnotify
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify
AVAHI_CONFIGURE_ENABLE=	sharing
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app

.include <bsd.port.mk>
