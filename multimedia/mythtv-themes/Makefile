#
# Ports collection makefile for:        mythtv-themes
# Date created:                         18 September 2008
# Whom:                                 Bernhard Fröhlich <decke@bluelife.at>
#
# $FreeBSD$

PORTNAME=	mythtv
PORTVERSION=	0.23
CATEGORIES=	multimedia
MASTER_SITES=	http://ftp.osuosl.org/pub/mythtv/ \
		http://ftp.oregonstate.edu/pub/mythtv/
PKGNAMESUFFIX=	-themes
DISTNAME=	myththemes-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	The official MythTV Themes for your PVR

BUILD_DEPENDS=	mythfrontend:${PORTSDIR}/multimedia/mythtv-frontend

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build

CONFIGURE_ENV+=	QMAKESPEC="${QMAKESPEC}"

CONFIGURE_ARGS=	--prefix="${PREFIX}"

QMAKESPEC?=	${LOCALBASE}/share/qt4/mkspecs/freebsd-g++

.include <bsd.port.mk>
