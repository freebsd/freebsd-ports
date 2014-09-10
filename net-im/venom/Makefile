# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	Venom
PORTVERSION=	0.2.0.140908
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Cross-platform GUI for Tox written in Vala using GTK+

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala	\
		${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee	\
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	naxuroqa
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7fa007d

USES=		cmake desktop-file-utils pkgconfig gettext
USE_GNOME=	glib20 gtk30
USE_SQLITE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		QRCODE NOTIFY
OPTIONS_DEFAULT=	QRCODE NOTIFY
QRCODE_DESC=		Show QR codes
QRCODE_CMAKE_ON=	-DENABLE_QR_ENCODE:BOOL="ON"
QRCODE_LIB_DEPENDS=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
NOTIFY_CMAKE_ON=	-DENABLE_LIBNOTIFY:BOOL="ON"
NOTIFY_LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

.include <bsd.port.mk>
