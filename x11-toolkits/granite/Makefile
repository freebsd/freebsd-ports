# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	granite
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://launchpadlibrarian.net/176306383/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION:R}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Extensions of Gtk+ toolkit

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee
RUN_DEPENDS=	contractor:${PORTSDIR}/sysutils/contractor

USE_GCC=	yes
USES=	cmake pkgconfig gettext
USE_GNOME=	glib20 gtk30 introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
