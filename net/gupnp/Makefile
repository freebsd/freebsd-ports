# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp
PORTVERSION=	0.20.8
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.6.4:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	libgssdp-1.0.so:${PORTSDIR}/net/gssdp \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--enable-introspection=yes
CONFIGURE_ENV=	VAPIGEN=""
GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig shebangfix

SHEBANG_FILES=	tools/gupnp-binding-tool
python_CMD=	${PYTHON_CMD}

.include <bsd.port.mk>
