PORTNAME=	osinfo-db-tools
DISTVERSION=	1.12.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Tools for managing the osinfo database
WWW=		https://libosinfo.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		gettext gnome libarchive meson pkgconfig tar:xz
USE_GNOME=	glib20 intltool libxml2

.include <bsd.port.mk>
