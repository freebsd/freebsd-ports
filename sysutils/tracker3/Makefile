PORTNAME=	tracker
PORTVERSION=	3.5.3
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Object database, tag/metadata database, search tool and indexer
WWW=		https://wiki.gnome.org/Projects/Tracker

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR}
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libicutu.so:devel/icu \
		libjson-glib-1.0.so:devel/json-glib \
		libuuid.so:misc/e2fsprogs-libuuid
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>=0:devel/py-gobject3@${PY_FLAVOR}

USES=		compiler:c++11-lib gettext gnome localbase:ldflags meson \
		pkgconfig python:build sqlite tar:xz vala:build
USE_GNOME=	glib20 libxml2 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dbash_completion=true \
		-Dbash_completion_dir=${PREFIX}/etc/bash_completion.d \
		-Ddocs=false \
		-Dstemmer=disabled \
		-Dsystemd_user_services=false

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTSCOUT=	limitw:1,even

OPTIONS_DEFINE=		DOCS MAN
OPTIONS_SUB=		yes

OPTIONS_MULTI=		SOUP
OPTIONS_MULTI_SOUP=	SOUP2 SOUP3

OPTIONS_DEFAULT=	SOUP2

SOUP2_DESC=		libsoup 2 backend (from devel/libsoup)
SOUP3_DESC=		libsoup 3 backend (from devel/libsoup3)

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	docs
MAN_BUILD_DEPENDS=	asciidoc:textproc/asciidoc
MAN_MESON_TRUE=		man
MAN_DESC=		Install manual pages

SOUP2_LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup
SOUP3_LIB_DEPENDS=	libsoup-3.0.so:devel/libsoup3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUP2} && ${PORT_OPTIONS:MSOUP3}
MESON_ARGS+=		-Dsoup=soup2,soup3
.elif ${PORT_OPTIONS:MSOUP2}
MESON_ARGS+=		-Dsoup=soup2
.else # SOUP3
MESON_ARGS+=		-Dsoup=soup3
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/etc/asciidoc|${PYTHONPREFIX_SITELIBDIR}/asciidoc/resources|' \
		${WRKSRC}/docs/manpages/meson.build

.include <bsd.port.post.mk>
