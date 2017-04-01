# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	osinfo-db-tools
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://releases.pagure.org/libosinfo/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Tools for managing the osinfo database

USES=		gettext gmake libarchive pkgconfig
USE_GNOME=	glib20 intltool libxml2 libxslt
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
