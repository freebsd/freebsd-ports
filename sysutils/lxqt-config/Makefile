# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-config
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	LXQT
DIST_SUBDIR=	lxqt

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt system settings center

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi

USES=	cmake:outsource compiler:c++11-lib kde:5 localbase:ldflags lxqt qt:5 \
	pkgconfig tar:xz
USE_QT=	buildtools_build qmake_build concurrent core dbus \
	gui linguisttools svg widgets x11extras xml
USE_KDE=	libkscreen windowsystem
USE_LXQT=	buildtools lxqt
USE_XORG=	ice sm x11 xcb xcursor xext xfixes xrandr
USE_LDCONFIG=	yes

.include <bsd.port.mk>
