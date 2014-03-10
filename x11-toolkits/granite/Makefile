# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	granite
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://launchpadlibrarian.net/159802745/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Extensions of Gtk+ toolkit

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee

USE_GCC=	yes
USES=	cmake pkgconfig gettext
USE_GNOME=	glib20 gtk30 introspection:build
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gee-1.0|gee-0.8|' ${WRKSRC}/lib/granite.deps

.include <bsd.port.mk>
