# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-igd
PORTVERSION=	0.2.2
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		gobject-introspection>=0.10:${PORTSDIR}/devel/gobject-introspection \
		gupnp>=0.18:${PORTSDIR}/net/gupnp
LIB_DEPENDS=	libgupnp-1.0.so:${PORTSDIR}/net/gupnp
RUN_DEPENDS=	gupnp>=0.18:${PORTSDIR}/net/gupnp

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XZ=		yes
USES=		gmake pathfix pkgconfig

post-patch:
	@${REINPLACE_CMD} -e '/ --define-variable=/d' ${WRKSRC}/configure

.include <bsd.port.mk>
