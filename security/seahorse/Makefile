# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$
#   $MCom: ports/trunk/security/seahorse3/Makefile 18480 2013-05-17 20:20:19Z kwm $

PORTNAME=	seahorse
PORTVERSION=	3.6.3
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgpgme.so:${PORTSDIR}/security/gpgme \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring \
		libcryptui.so:${PORTSDIR}/security/libcryptui \
		libgcr-3.so:${PORTSDIR}/security/gcr \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

USE_XORG=	sm
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	intlhack gnomeprefix gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml

OPTIONS_DEFINE=	LDAP NOTIFY AVAHI
OPTIONS_DEFAULT=LDAP NOTIFY AVAHI

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.else
CONFIGURE_ARGS+=--disable-ldap
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-client.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-sharing
.endif

.include <bsd.port.mk>
