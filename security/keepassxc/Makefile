# $FreeBSD$

PORTNAME=	keepassxc
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	melanhit@gmail.com
COMMENT=	KeePass Cross-platform Community Edition

LICENSE=	BOOST-1.0 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_BOOST-1.0=	Boost Software License version 1.0
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_BOOST-1.0=	${WRKSRC}/LICENSE.BOOST-1.0
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_BOOST-1.0=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

CONFLICTS_INSTALL=	keepassx-0.* keepassx2-* keepassx-*

USES=		cmake compiler:c++11-lib desktop-file-utils shared-mime-info
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT5=	buildtools_build concurrent core dbus gui linguisttools network \
		qmake_build testlib widgets x11extras
USE_XORG=	ice inputproto sm x11 xcursor xext xfixes xi xrandr xrender \
		xt xtst

USE_GITHUB=	yes
GH_ACCOUNT=	keepassxreboot

CMAKE_ARGS+=	-DZLIB_SUPPORTS_GZIP:BOOL=ON -DWITH_XC_AUTOTYPE=ON -DWITH_XC_HTTP=ON

.include <bsd.port.mk>
