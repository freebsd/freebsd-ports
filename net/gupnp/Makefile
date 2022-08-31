PORTNAME=	gupnp
PORTVERSION=	1.5.3
CATEGORIES=	net
MASTER_SITES=	GNOME

PATCH_SITES=	https://gitlab.gnome.org/GNOME/gupnp/-/commit/
PATCHFILES=	1296d10eda308792d2924f141d72b8b6818878bd.diff:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	glib>=2.69:devel/glib20 \
		gobject-introspection>=1.36:devel/gobject-introspection \
		gssdp>=1.5.0:net/gssdp \
		libsoup3>=2.99.0:devel/libsoup3
LIB_DEPENDS=	libgssdp-1.6.so:net/gssdp \
		libsoup-3.0.so:devel/libsoup3 \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c11 cpe gnome meson pkgconfig python:run shebangfix tar:xz
USE_GNOME=	glib20 introspection:build libxml2

MESON_ARGS=	-Dexamples=false -Dgtk_doc=false -Dintrospection=true
USE_CSTD=	c11
USE_LDCONFIG=	yes

CPE_VENDOR=	gnome

CONFLICTS_INSTALL=	gupnp14

SHEBANG_FILES=	tools/gupnp-binding-tool

OPTIONS_DEFINE=	VAPI
OPTIONS_SUB=	yes

VAPI_MESON_TRUE=	vapi
VAPI_USES=		vala:build

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "clang"
CPPFLAGS+=	-Wno-return-type
.endif

.include <bsd.port.post.mk>
