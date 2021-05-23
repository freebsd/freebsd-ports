# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	gcr
PORTVERSION=	3.40.0
CATEGORIES=	security gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for bits of crypto UI and parsing

BUILD_DEPENDS=	gpg2:security/gnupg \
		vapigen:lang/vala
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgpg-error.so:security/libgpg-error \
		libp11-kit.so:security/p11-kit \
		libgcrypt.so:security/libgcrypt

CONFLICTS=	gnome-keyring-2.[0-9]*
PORTSCOUT=	limitw:1,even

USE_GNOME=	cairo gtk30 intlhack introspection:build
USES=		desktop-file-utils gettext gmake gnome libtool meson pathfix \
		pkgconfig python:3.6+ shared-mime-info tar:xz
USE_LDCONFIG=	yes
BINARY_ALIAS=	python3=${PYTHON_VERSION}
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.crypto.pgp.gschema.xml

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	gtk_doc
DOCSDIR=		${PREFIX}/share/gtk-doc/html/

.include <bsd.port.mk>
