# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-igd
PORTVERSION=	0.2.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.10:devel/gobject-introspection \
		gupnp>=0.18:net/gupnp
LIB_DEPENDS=	libgssdp-1.2.so:net/gssdp \
		libgupnp-1.2.so:net/gupnp
RUN_DEPENDS=	gupnp>=0.18:net/gupnp

USES=		compiler:c11 gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

CONFIGURE_ARGS=	--enable-introspection=yes --disable-python
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gssdp-1.0|gssdp-1.2|; s|gupnp-1.0|gupnp-1.2|' ${WRKSRC}/configure ${WRKSRC}/gupnp-igd-1.0.pc.in ${WRKSRC}/libgupnp-igd/Makefile.in ${WRKSRC}/libgupnp-igd/GUPnPIgd-1.0.gir
	@${REINPLACE_CMD} -e '/ --define-variable=/d' ${WRKSRC}/configure

.include <bsd.port.mk>
