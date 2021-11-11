# Created by: Olivier Duchateau

PORTNAME=	adwaita-qt
DISTVERSION=	1.4.1
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	5

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	Adwaita theme for Qt applications

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	sassc:textproc/sassc

USES=		cmake compiler:c++11-lib localbase pkgconfig qt:5 xorg
USE_QT=		core dbus gui widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb
CMAKE_OFF=	USE_QT4

USE_GITHUB=	yes
GH_ACCOUNT=	FedoraQt

.include <bsd.port.mk>
