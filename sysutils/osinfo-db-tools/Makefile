# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osinfo-db-tools
PORTVERSION=	1.7.0
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Tools for managing the osinfo database

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libsoup-2.4.so:devel/libsoup

USES=		gettext gmake gnome libarchive pkgconfig tar:xz meson
USE_GNOME=	glib20 intltool libxml2 libxslt

.include <bsd.port.mk>
