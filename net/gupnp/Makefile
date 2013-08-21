# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp
PORTVERSION=	0.20.5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for UPnP devices

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.6.4:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gssdp-1.0:${PORTSDIR}/net/gssdp \
		soup-2.4:${PORTSDIR}/devel/libsoup \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

CONFIGURE_ARGS=	--enable-introspection=yes
CONFIGURE_ENV=	VAPIGEN=""
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/tools/gupnp-binding-tool

.include <bsd.port.mk>
