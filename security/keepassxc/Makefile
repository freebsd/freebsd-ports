# $FreeBSD$

PORTNAME=	keepassxc
PORTVERSION=	2.2.1
CATEGORIES=	security

MAINTAINER=	melanhit@gmail.com
COMMENT=	KeePass Cross-platform Community Edition

LICENSE=	APACHE20 BOOST-1.0 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 NOKIA-LGPL-EXCEPTION
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

USES=		cmake:outsource compiler:c++11-lib desktop-file-utils shared-mime-info
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_QT5=	buildtools_build concurrent core dbus gui linguisttools network \
		qmake_build testlib widgets
USE_XORG=	ice inputproto sm x11 xcursor xext xfixes xrandr xrender xt

USE_GITHUB=	yes
GH_ACCOUNT=	keepassxreboot

CMAKE_ARGS+=	-DZLIB_SUPPORTS_GZIP:BOOL=ON

OPTIONS_DEFINE=		AUTOTYPE HTTP YUBIKEY TEST
OPTIONS_DEFAULT=	AUTOTYPE HTTP
OPTIONS_SUB=		yes

AUTOTYPE_CMAKE_BOOL=	WITH_XC_AUTOTYPE
AUTOTYPE_DESC=		Auto-type passwords in input fields
AUTOTYPE_USE=		QT5=x11extras XORG=xi,xtst

HTTP_CMAKE_BOOL=	WITH_XC_HTTP
HTTP_DESC=		KeePassHTTP support for ChromeIPass and PassIFox

YUBIKEY_CMAKE_BOOL=	WITH_XC_YUBIKEY
YUBIKEY_DESC=		Include YubiKey support
YUBIKEY_LIB_DEPENDS=	libyubikey.so:security/libyubikey \
			libykpers-1.so:security/ykpers

TEST_CMAKE_BOOL=	WITH_TESTS WITH_GUI_TESTS
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|Q_OS_LINUX|Q_OS_UNIX|g' \
		${WRKSRC}/src/core/ScreenLockListenerPrivate.cpp \
		${WRKSRC}/src/gui/MainWindow.cpp \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
