# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-av
PORTVERSION=	0.12.8
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.9.5:devel/gobject-introspection \
		gupnp>=0.19.0:net/gupnp
LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp
RUN_DEPENDS=	gupnp>=0.19.0:net/gupnp

OPTIONS_DEFINE=	VALA
OPTIONS_SUB=	yes
VALA_DESC=	Vala binding (requires net/gssdp and net/gupnp with VALA enabled)

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz

PORTDATA=	*

VALA_BUILD_DEPENDS=	vala>=0.22:lang/vala
VALA_CONFIGURE_ENV=	ac_cv_path_VAPIGEN=${LOCALBASE}/bin/vapigen
VALA_CONFIGURE_ENV_OFF=	ac_cv_path_VAPIGEN=""

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-parameters||' ${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
