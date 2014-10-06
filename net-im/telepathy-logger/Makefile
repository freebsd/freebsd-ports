# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/branches/GNOME_3_12/net-im/telepathy-logger/Makefile 19916 2014-09-25 22:45:14Z kwm $

PORTNAME=	telepathy-logger
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Logger utility library for the Telepathy framework

LICENSE=	LGPL21

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libtelepathy-glib.so:${PORTSDIR}/net-im/telepathy-glib

USES=		gmake libtool pathfix pkgconfig python:build tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20 gnomedocutils intltool libxml2 \
		libxslt:build introspection:build
USE_SQLITE=	yes
GLIB_SCHEMAS=	org.freedesktop.Telepathy.Logger.gschema.xml
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|/usr/bin/env python|g' \
		${WRKSRC}/tools/*.py

.include <bsd.port.mk>
