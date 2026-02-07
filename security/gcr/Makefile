PORTNAME=	gcr
PORTVERSION=	4.4.0.1
CATEGORIES=	security gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing
WWW=		https://gitlab.gnome.org/GNOME/gcr

BUILD_DEPENDS=	gpg2:security/gnupg
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt

USES=		gettext gnome meson pkgconfig python:env tar:xz \
		vala:build
USE_GNOME=	glib20 gtk40 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dsystemd=disabled \
		-Dgtk_doc=false

.include <bsd.port.mk>
