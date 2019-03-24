# $FreeBSD$

PORTNAME=	keepassxc
DISTVERSION=	2.4.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/keepassxreboot/keepassxc/releases/download/${DISTVERSION}/${PORTNAME}-${DISTVERSION}-src.tar.xz?dummy=/

MAINTAINER=	melanhit@gmail.com
COMMENT=	KeePass Cross-platform Community Edition

LICENSE=	APACHE20 BOOST-1.0 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 \
		LGPL3 NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_BOOST-1.0=			Boost Software License version 1.0
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_BOOST-1.0=			${WRKSRC}/LICENSE.BOOST-1.0
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_BOOST-1.0=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libqrencode.so:graphics/libqrencode

USES=		cmake compiler:c++11-lang desktop-file-utils qt:5 \
		shared-mime-info tar:xz
USE_QT=		buildtools_build concurrent core dbus gui linguisttools network \
		qmake_build svg testlib widgets
USE_XORG=	x11
USE_LDCONFIG=	yes

# patching CMakeLists.txt does not help because that is being overided by
# cmake/GNUInstallDirs.cmake
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man

CONFLICTS_INSTALL=	keepassx-0.* keepassx2-* keepassx-*

OPTIONS_DEFINE=		AUTOTYPE BROWSER KEESHARE NETWORKING YUBIKEY SSHAGENT TEST
OPTIONS_DEFAULT=	AUTOTYPE BROWSER KEESHARE NETWORKING SSHAGENT
OPTIONS_SUB=		yes

AUTOTYPE_CMAKE_BOOL=	WITH_XC_AUTOTYPE
AUTOTYPE_DESC=		Auto-type passwords in input fields
AUTOTYPE_USE=		QT=x11extras XORG=xi,xtst

BROWSER_CMAKE_BOOL=	WITH_XC_BROWSER
BROWSER_DESC=		Browser integration with KeePassXC-Browser
BROWSER_LIB_DEPENDS=	libsodium.so:security/libsodium

KEESHARE_CMAKE_BOOL=	WITH_XC_KEESHARE WITH_XC_KEESHARE_SECURE
KEESHARE_DESC=		Sharing integration with KeeShare
KEESHARE_LIB_DEPENDS=	libquazip5.so:archivers/quazip

# Legacy/Deprecated.
NETWORKING_CMAKE_BOOL=	WITH_XC_NETWORKING
NETWORKING_DESC=	Networking support (e.g. for downloading website icons)

SSHAGENT_CMAKE_BOOL=	WITH_XC_SSHAGENT
SSHAGENT_DESC=		SSH agent support

YUBIKEY_CMAKE_BOOL=	WITH_XC_YUBIKEY
YUBIKEY_DESC=		YubiKey support
YUBIKEY_LIB_DEPENDS=	libykpers-1.so:security/ykpers \
			libyubikey.so:security/libyubikey

TEST_CMAKE_BOOL=	WITH_TESTS WITH_GUI_TESTS
TEST_TEST_TARGET=	test

post-patch:
	@${REINPLACE_CMD} -e 's|Q_OS_LINUX|Q_OS_UNIX|g' \
		${WRKSRC}/src/browser/HostInstaller.cpp

.include <bsd.port.mk>
