# Created by: Dave McKay <dave@mu.org>
# $FreeBSD$

PORTNAME=	seahorse
PORTVERSION=	3.36.2
PORTREVISION=	1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnupg>=2.1.4:security/gnupg \
		itstool:textproc/itstool \
		valac:lang/vala
LIB_DEPENDS=	libgcr-base-3.so:security/gcr \
		libgpgme.so:security/gpgme \
		libhandy-0.0.so:x11-toolkits/libhandy0 \
		libpwquality.so:security/libpwquality \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	gnupg>=2.1.4:security/gnupg

USES=		gettext gnome localbase:ldflags meson pkgconfig \
		python:3.5+,build tar:xz xorg
USE_CSTD=	c99
USE_GNOME=	gtk30
GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
USE_XORG=	sm

MESON_ARGS=	-Dcheck-compatible-gpg=false \
		-Dhkp-support=true \
		-Dkeyservers-support=true \
		-Dpgp-support=true \
		-Dpkcs11-support=true

BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		AVAHI LDAP
OPTIONS_DEFAULT=	AVAHI LDAP
OPTIONS_SUB=		yes

AVAHI_DESC=	DNS-SD key sharing
LDAP_DESC=	LDAP keyserver support (for gpg)

AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	key-sharing
LDAP_USE=		OPENLDAP=yes
LDAP_MESON_TRUE=	ldap-support

.include <bsd.port.mk>
