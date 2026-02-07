PORTNAME=	seahorse
PORTVERSION=	47.0.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/seahorse/-/commit/
PATCHFILES+=	aa68522cc696fa491ccfdff735b77bcf113168d0.patch:-p1 # Fix build with GpgME 2.0.0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME application for managing encryption keys (PGP, SSH)
WWW=		https://wiki.gnome.org/Apps/Seahorse \
		https://gitlab.gnome.org/GNOME/seahorse

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gnupg>=2.1.4:security/gnupg \
		itstool:textproc/itstool
LIB_DEPENDS=	libgcr-base-3.so:security/gcr3 \
		libgpgme.so:security/gpgme \
		libhandy-1.so:x11-toolkits/libhandy \
		libpwquality.so:security/libpwquality \
		libsecret-1.so:security/libsecret \
		libsoup-3.0.so:devel/libsoup3
RUN_DEPENDS=	gnupg>=2.1.4:security/gnupg

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig \
		python:build tar:xz vala:build xorg
CPE_VENDOR=	gnome
USE_CSTD=	c99
USE_GNOME=	gtk30
GLIB_SCHEMAS=	org.gnome.seahorse.gschema.xml \
		org.gnome.seahorse.manager.gschema.xml \
		org.gnome.seahorse.window.gschema.xml
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
LDAP_USES=		ldap
LDAP_MESON_TRUE=	ldap-support

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
