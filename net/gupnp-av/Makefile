# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-av
PORTVERSION=	0.12.5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.9.5:${PORTSDIR}/devel/gobject-introspection \
		gupnp>=0.19.0:${PORTSDIR}/net/gupnp
LIB_DEPENDS=	libgupnp-1.0.so:${PORTSDIR}/net/gupnp
RUN_DEPENDS=	gupnp>=0.19.0:${PORTSDIR}/net/gupnp

CONFIGURE_ARGS=	--enable-introspection=yes
CONFIGURE_ENV=	VAPIGEN="" ac_cv_path_VAPIGEN=""
GNU_CONFIGURE=	yes
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig tar:xz

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-parameters||' ${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
