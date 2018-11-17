# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-av
PORTVERSION=	0.12.11
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.9.5:devel/gobject-introspection

OPTIONS_DEFINE=	VAPI
OPTIONS_SUB=	yes

USES=		gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

VAPI_BUILD_DEPENDS=	vala>=0.22:lang/vala
VAPI_CONFIGURE_ENV=	ac_cv_path_VAPIGEN=${LOCALBASE}/bin/vapigen
VAPI_CONFIGURE_ENV_OFF=	ac_cv_path_VAPIGEN=""

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-parameters||' ${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
