# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	Venom
PORTVERSION=	0.2.0.140314
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A cross-platform GUI for Tox written in Vala using GTK+

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libtoxcore.so:${PORTSDIR}/net-im/tox	\
		libgee-0.8.so:${PORTSDIR}/devel/libgee	\
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

USE_GITHUB=	yes
GH_ACCOUNT=	naxuroqa
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	86f4e45

USES=		cmake desktop-file-utils pkgconfig
USE_GNOME=	glib20 gtk30
USE_SQLITE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
