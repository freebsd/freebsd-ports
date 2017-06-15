# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-av
PORTVERSION=	0.12.10
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.9.5:devel/gobject-introspection

OPTIONS_DEFINE=	VALA
OPTIONS_SUB=	yes
VALA_DESC=	Vala binding

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	glib20 introspection:build libxml2
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig tar:xz

PORTDATA=	*

VALA_BUILD_DEPENDS=	vala>=0.22:lang/vala
VALA_CONFIGURE_ENV=	ac_cv_path_VAPIGEN=${LOCALBASE}/bin/vapigen
VALA_CONFIGURE_ENV_OFF=	ac_cv_path_VAPIGEN=""

post-patch:
	@${REINPLACE_CMD} -e 's|-Wno-unused-parameters||' ${WRKSRC}/tests/Makefile.in

.include <bsd.port.mk>
