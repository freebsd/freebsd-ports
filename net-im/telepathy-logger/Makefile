# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-logger/Makefile,v 1.14 2012/08/17 19:06:45 kwm Exp $

PORTNAME=	telepathy-logger
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		telepathy-glib:${PORTSDIR}/net-im/telepathy-glib

LICENSE=	LGPL21

USES=		pkgconfig
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 intltool gnomedocutils ltverhack libxml2 \
		libxslt:build
USE_SQLITE=	yes
USE_PYTHON_BUILD=	yes
GLIB_SCHEMAS=	org.freedesktop.Telepathy.Logger.gschema.xml

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
