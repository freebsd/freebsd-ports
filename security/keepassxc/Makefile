PORTNAME=	keepassxc
DISTVERSION=	2.6.6
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://github.com/keepassxreboot/keepassxc/releases/download/${DISTVERSION}/${PORTNAME}-${DISTVERSION}-src.tar.xz?dummy=/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	KeePass Cross-platform Community Edition

LICENSE=	APACHE20 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 MIT \
		NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libqrencode.so:graphics/libqrencode \
		libsodium.so:security/libsodium

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig qt:5 \
		readline shared-mime-info tar:xz xorg
USE_QT=		concurrent core dbus gui network svg widgets buildtools_build \
		linguisttools_build qmake_build testlib_build
USE_XORG=	x11

CMAKE_OFF=	WITH_XC_UPDATECHECK

CONFLICTS_INSTALL=	keepassx-0.* keepassx2 keepassx

OPTIONS_DEFINE=		AUTOTYPE BROWSER FDOSECRETS KEESHARE NETWORKING SSHAGENT YUBIKEY TEST
OPTIONS_DEFAULT=	AUTOTYPE BROWSER FDOSECRETS KEESHARE NETWORKING SSHAGENT YUBIKEY
OPTIONS_SUB=		yes

AUTOTYPE_CMAKE_BOOL=	WITH_XC_AUTOTYPE
AUTOTYPE_DESC=		Auto-type passwords in input fields
AUTOTYPE_USE=		QT=x11extras XORG=xi,xtst

BROWSER_CMAKE_BOOL=	WITH_XC_BROWSER
BROWSER_DESC=		Browser integration with KeePassXC-Browser

FDOSECRETS_CMAKE_BOOL=	WITH_XC_FDOSECRETS
FDOSECRETS_DESC=	freedesktop.org secrets service support

KEESHARE_CMAKE_BOOL=	WITH_XC_KEESHARE WITH_XC_KEESHARE_SECURE
KEESHARE_DESC=		Sharing integration with KeeShare
KEESHARE_LIB_DEPENDS=	libquazip1-qt5.so:archivers/quazip

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

.include <bsd.port.mk>
