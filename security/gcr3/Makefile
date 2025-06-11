PORTNAME=	gcr
PORTVERSION=	3.41.2
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	3

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing
WWW=		https://gitlab.gnome.org/GNOME/gcr

BUILD_DEPENDS=	gpg2:security/gnupg
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gpg2:security/gnupg

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gnome meson pkgconfig python \
		shared-mime-info tar:xz vala:build
USE_GNOME=	cairo glib20 gdkpixbuf gtk30 introspection:build
MESON_ARGS=	-Dsystemd=disabled \
		-Dgtk_doc=false
# Avoid conflicts with security/gcr -> /usr/local/libexec/gcr-ssh-agent
MESON_ARGS+=	-Dssh_agent=false
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

.include <bsd.port.mk>
