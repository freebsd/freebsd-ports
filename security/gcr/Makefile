PORTNAME=	gcr
PORTVERSION=	4.3.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing
WWW=		https://live.gnome.org/GnomeKeyring

BUILD_DEPENDS=	gpg2:security/gnupg
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*

USE_GNOME=	gtk40 intlhack introspection:build
USES=		gettext gnome meson pkgconfig python:env tar:xz \
		vala:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dsystemd=disabled

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen@${PY_FLAVOR}
DOCS_MESON_TRUE=	gtk_doc

.include <bsd.port.mk>
