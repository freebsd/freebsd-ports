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
LICENSE_FILES=	${FILES}/COPYING

BUILD_DEPENDS=	gnupg>=2.1.4:security/gnupg \
		valac:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libgpgme.so:security/gpgme \
		libgcr-base-3.so:security/gcr \
		libsecret-1.so:security/libsecret \
		libsoup-2.4.so:devel/libsoup \
		libpwquality.so:security/libpwquality \
		libhandy-0.0.so:x11-toolkits/libhandy0
RUN_DEPENDS=	gnupg>=2.1.4:security/gnupg

PORTSCOUT=	limitw:1,even

USE_XORG=	sm
USE_LDCONFIG=	yes
USES=		gettext gnome localbase:ldflags meson pkgconfig \
		python:3.5+,build tar:xz xorg
USE_CSTD=	c99
USE_GNOME=	gtk30
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml

MESON_ARGS=	-Dcheck-compatible-gpg=false \
		-Dpgp-support=true \
		-Dpkcs11-support=true \
		-Dkeyservers-support=true \
		-Dhkp-support=true \
		-Dhkp-support=true

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	LDAP AVAHI
OPTIONS_DEFAULT=LDAP AVAHI
LDAP_MESON_TRUE=	ldap-support
LDAP_USE=	OPENLDAP=yes
LDAP_DESC=	LDAP keyserver support (for gpg)
AVAHI_DESC=	DNS-SD key sharing
AVAHI_MESON_TRUE=	key-sharing
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
