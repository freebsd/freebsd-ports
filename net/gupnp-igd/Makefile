# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-igd
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.10:devel/gobject-introspection \
		gupnp>=0.18:net/gupnp
LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp
RUN_DEPENDS=	gupnp>=0.18:net/gupnp

OPTIONS_DEFINE=	PYTHON
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USES=		gmake gnome libtool pathfix pkgconfig tar:xz

PYTHON_CONFIGURE_ENABLE=python
PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject>=2.12.0:devel/py-gobject@${PY_FLAVOR}
PYTHON_USES=		python:2.7

post-patch:
	@${REINPLACE_CMD} -e '/ --define-variable=/d' ${WRKSRC}/configure

.include <bsd.port.mk>
