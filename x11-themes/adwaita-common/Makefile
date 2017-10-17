# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	adwaita
PORTVERSION=	1.0
PORTREVISION?=	1
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	-${OPTIONS_SLAVE:tl}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Adwaita theme for Qt applications

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

OPTIONS_DEFINE=	QT4 QT5 COMMON
OPTIONS_EXCLUDE=${OPTIONS_DEFINE}

OPTIONS_SLAVE?=	COMMON

COMMON_RUN_DEPENDS=	adwaita-qt4>=${PORTVERSION}:x11-themes/adwaita-qt4 \
			adwaita-qt5>=${PORTVERSION}:x11-themes/adwaita-qt5
COMMON_USES=		metaport
COMMON_PLIST_FILES=	# none

# Set the values for the QT[45] slave ports -- COMMON is ignored, as it is already set.
${OPTIONS_SLAVE}_USES?=	cmake:outsource compiler:c++11-lib localbase pkgconfig
${OPTIONS_SLAVE}_PLIST_FILES?=	%%QT_PLUGINDIR%%/styles/adwaita.so

QT4_USE=	QT4=moc_build,rcc_build,uic_build,qmake_build,corelib,dbus,gui
QT4_CMAKE_BOOL=	USE_QT4

QT5_USE=	QT5=buildtools_build,qmake_build,core,dbus,gui,widgets
QT5_CMAKE_BOOL_OFF=	USE_QT4

USE_GITHUB=	yes
GH_ACCOUNT=	MartinBriza
GH_PROJECT=	adwaita-qt

.include <bsd.port.mk>
