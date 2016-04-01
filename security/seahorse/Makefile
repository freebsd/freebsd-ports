# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$

PORTNAME=	seahorse
PORTVERSION=	3.18.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

BUILD_DEPENDS=	gnupg>=2.1.4:security/gnupg \
		valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libgcr-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gnupg>=2.1.4:security/gnupg

PORTSCOUT=	limitw:1,even

USE_XORG=	sm
USE_LDCONFIG=	yes
USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	intlhack gnomeprefix gtk30
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP AVAHI
OPTIONS_DEFAULT=LDAP AVAHI
LDAP_CONFIGURE_ENABLE=	ldap
LDAP_USE=	OPENLDAP=yes
LDAP_DESC=	LDAP keyserver support (for gpg)
AVAHI_DESC=	DNS-SD key sharing
AVAHI_CONFIGURE_ENABLE=	sharing
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

.include <bsd.port.mk>
