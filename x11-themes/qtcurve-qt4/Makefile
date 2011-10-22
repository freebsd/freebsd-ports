# New ports collection makefile for:	qtcurve-qt4
# Date created:		2010-05-25
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qtcurve
PORTVERSION=	1.8.9
CATEGORIES=	x11-themes
MASTER_SITES=	http://craigd.wikispaces.com/file/view/
PKGNAMEPREFIX=	qt4-style-
DISTNAME=	QtCurve-KDE4-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	QtCurve Qt4 widget style

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui svg imageformats_run \
		qmake_build uic_build moc_build rcc_build
CFLAGS+=	-I${LOCALBASE}/include
CMAKE_ARGS+=	-DQTC_QT_ONLY:BOOL=ON \
		-DQTC_DISABLE_KDEFILEDIALOG_CALLS:BOOL=ON

PLIST_FILES=	${QT_PLUGINDIR_REL}/styles/qtcurve.so
PLIST_DIRSTRY=	${QT_PLUGINDIR_REL}/styles

.include <bsd.port.mk>
