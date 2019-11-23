# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	adwaita-qt
DISTVERSION=	1.1.1
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	5

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Adwaita theme for Qt applications

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

USES=		cmake compiler:c++11-lib localbase pkgconfig qt:5
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build
CMAKE_OFF=	USE_QT4

USE_GITHUB=	yes
GH_ACCOUNT=	FedoraQt

PLIST_FILES=	${QT_PLUGINDIR}/styles/adwaita.so

.include <bsd.port.mk>
