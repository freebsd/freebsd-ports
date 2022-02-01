PORTNAME=	tracker
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libicutu.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:3.6+,build sqlite tar:xz
USE_GNOME=	glib20 libxml2 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbash_completion=true \
		-Dbash_completion_dir=${PREFIX}/etc/bash_completion.d \
		-Ddocs=false \
		-Dman=false \
		-Dstemmer=disabled \
		-Dsystemd_user_services=false

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTSCOUT=	limitw:1,even

PLIST_SUB=	LIBVER=0.304.0

OPTIONS_DEFINE=		DOCS MAN
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	docs
MAN_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
MAN_MESON_TRUE=		man

post-patch:
	${REINPLACE_CMD} -e 's^/etc/asciidoc^${PREFIX}/etc/asciidoc^' \
		${WRKSRC}/docs/manpages/meson.build

.include <bsd.port.mk>
