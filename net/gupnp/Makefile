# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp
PORTVERSION=	0.20.17
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.6.4:devel/gobject-introspection \
		gssdp>=0.14.13:net/gssdp
LIB_DEPENDS=	libgssdp-1.0.so:net/gssdp \
		libsoup-2.4.so:devel/libsoup \
		libuuid.so:misc/e2fsprogs-libuuid

OPTIONS_DEFINE=	VALA
OPTIONS_SUB=	yes
VALA_DESC=	Vala binding (requires net/gssdp with VALA enabled)

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USE_CSTD=	c11
USES=		compiler:c11 gmake libtool pathfix pkgconfig python:run shebangfix tar:xz

SHEBANG_FILES=	tools/gupnp-binding-tool

VALA_BUILD_DEPENDS=	vala>=0.20:lang/vala
VALA_CONFIGURE_ENV=	ac_cv_path_VAPIGEN=${LOCALBASE}/bin/vapigen
VALA_CONFIGURE_ENV_OFF=	ac_cv_path_VAPIGEN=""

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == "clang"
CPPFLAGS+=	-Wno-return-type
.endif

.include <bsd.port.post.mk>
