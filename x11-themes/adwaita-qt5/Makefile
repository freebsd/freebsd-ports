# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	adwaita
PORTVERSION=	0.97
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	-qt5

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Adwaita theme for Qt5 applications

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	MartinBriza
GH_PROJECT=	adwaita-qt

MASTERDIR=	${.CURDIR}/../adwaita-common
DISTINFO_FILE=	${MASTERDIR}/distinfo
DESCR=	${MASTERDIR}/pkg-descr
PLIST_FILES=	%%QT_PLUGINDIR%%/styles/adwaita.so

USES=	cmake:outsource compiler:c++11-lib localbase pkgconfig
USE_QT5=	buildtools_build qmake_build core dbus gui widgets

CMAKE_ARGS+=	-DBUILD_EXAMPLE:BOOL=OFF

.include <bsd.port.mk>
