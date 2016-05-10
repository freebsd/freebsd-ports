# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	adwaita
PORTVERSION=	0.4
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	-qt4

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Adwaita theme for Qt5 applications

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

RUN_DEPENDS=	adwaita-common>=0.4:x11-themes/adwaita-common

USE_GITHUB=	yes
GH_ACCOUNT=	MartinBriza
GH_PROJECT=	adwaita-qt

DISTINFO_FILE=	${.CURDIR}/../adwaita-common/distinfo
EXTRA_PATCHES=	${.CURDIR}/../adwaita-qt5/files/patch-CMakeLists.txt
PLIST_FILES=	%%QT_PLUGINDIR%%/styles/adwaita.so

USES=	cmake:outsource compiler:c++11-lib localbase pkgconfig
USE_QT4=	moc_build rcc_build uic_build qmake_build corelib gui

CMAKE_ARGS+=	-DBUILD_EXAMPLE:BOOL=OFF \
	-DUSE_QT4:BOOL=ON

.include <bsd.port.mk>
