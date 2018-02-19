# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/telepathy-logger/Makefile 19955 2014-10-15 10:15:00Z gusi $

PORTNAME=	telepathy-logger
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

LICENSE=	LGPL21

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libtelepathy-glib.so:net-im/telepathy-glib

USES=		gettext-tools gmake libtool pathfix pkgconfig python:2.7,build \
		sqlite tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomedocutils intltool libxml2 \
		libxslt:build introspection:build
GLIB_SCHEMAS=	org.freedesktop.Telepathy.Logger.gschema.xml
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
