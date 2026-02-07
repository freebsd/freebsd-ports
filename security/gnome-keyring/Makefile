PORTNAME=	gnome-keyring
PORTVERSION=	48.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Program that keeps passwords and other secrets
WWW=		https://gitlab.gnome.org/GNOME/gnome-keyring

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgpg-error.so:security/libgpg-error \
		libgcr-base-3.so:security/gcr3 \
		libtasn1.so:security/libtasn1 \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	pinentry-gnome3:security/pinentry-gnome

USE_GNOME=	cairo glib20 gtk30 libxslt:build
USES=		compiler:c11 cpe gettext meson gnome localbase \
		pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
MESON_ARGS=	-Dssh-agent=true \
		-Dselinux=disabled \
		-Dsystemd=disabled
GLIB_SCHEMAS=	org.gnome.crypto.cache.gschema.xml

SUB_FILES=	pkg-message

.include <bsd.port.mk>
