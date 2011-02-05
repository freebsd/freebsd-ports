# New ports collection makefile for:	kio-upnp-ms
# Date created:				2010-12-29
# Whom:					Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kio-upnp-ms
PORTVERSION=	0.8.0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KIO slave to access UPnP MediaServers

LIB_DEPENDS=	HUpnp.1:${PORTSDIR}/net/hupnp

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdehier kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	corelib network xml dbus gui \
		qmake_build moc_build rcc_build uic_build

PLIST_FILES=	include/kio/upnptypes.h \
		lib/kde4/kio_upnp_ms.so \
		share/kde4/services/kio_upnp_ms.protocol

.include <bsd.port.mk>
