# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	Venom
PORTVERSION=	0.2.0.140325
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A cross-platform GUI for Tox written in Vala using GTK+

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala	\
		${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee	\
		libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	naxuroqa
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	0165df4

USES=		cmake desktop-file-utils pkgconfig
USE_GNOME=	glib20 gtk30
USE_SQLITE=	yes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
