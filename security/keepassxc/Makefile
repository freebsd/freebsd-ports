PORTNAME=	keepassxc
DISTVERSION=	2.7.10
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://github.com/keepassxreboot/keepassxc/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	KeePass Cross-platform Community Edition
WWW=		https://keepassxc.org

LICENSE=	APACHE20 BSD3CLAUSE CC0-1.0 GPLv2 GPLv3 LGPL21 LGPL3 MIT \
		NOKIA-LGPL-EXCEPTION
LICENSE_COMB=	multi
LICENSE_NAME_NOKIA-LGPL-EXCEPTION=	Nokia Qt LGPL Exception version 1.1
LICENSE_FILE_NOKIA-LGPL-EXCEPTION=	${WRKSRC}/LICENSE.NOKIA-LGPL-EXCEPTION
LICENSE_PERMS_NOKIA-LGPL-EXCEPTION=	dist-mirror dist-sell pkg-mirror \
					pkg-sell auto-accept

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libargon2.so:security/libargon2 \
		libbotan-3.so:security/botan3 \
		libqrencode.so:graphics/libqrencode

USES=		cmake compiler:c++17-lang desktop-file-utils minizip \
		pkgconfig qt:5 readline shared-mime-info tar:xz xorg

USE_QT=		concurrent core dbus gui network svg widgets x11extras \
		buildtools:build linguisttools:build qmake:build testlib:build
USE_XORG=	x11

CMAKE_OFF=	WITH_XC_UPDATECHECK

CONFLICTS_INSTALL=	keepassx keepassx-0.* keepassx2 keepassxc276

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

OPTIONS_DEFINE=		AUTOTYPE BROWSER FDOSECRETS KEESHARE NETWORKING \
			SSHAGENT TEST YUBIKEY
OPTIONS_DEFAULT=	AUTOTYPE BROWSER FDOSECRETS KEESHARE NETWORKING \
			SSHAGENT
OPTIONS_SUB=		yes

AUTOTYPE_DESC=		Auto-type passwords in input fields
BROWSER_DESC=		Browser integration with KeePassXC-Browser
FDOSECRETS_DESC=	freedesktop.org secrets service support
KEESHARE_DESC=		Sharing integration with KeeShare
NETWORKING_DESC=	Networking support (e.g. for downloading website icons)
SSHAGENT_DESC=		SSH agent support
YUBIKEY_DESC=		YubiKey support (broken on <= 14.x)

AUTOTYPE_USE=		XORG=xi,xtst
AUTOTYPE_CMAKE_BOOL=	WITH_XC_AUTOTYPE

BROWSER_CMAKE_BOOL=	WITH_XC_BROWSER

FDOSECRETS_CMAKE_BOOL=	WITH_XC_FDOSECRETS

KEESHARE_CMAKE_BOOL=	WITH_XC_KEESHARE

NETWORKING_CMAKE_BOOL=	WITH_XC_NETWORKING

SSHAGENT_CMAKE_BOOL=	WITH_XC_SSHAGENT

TEST_CMAKE_BOOL=	WITH_GUI_TESTS WITH_TESTS
TEST_TEST_TARGET=	test

YUBIKEY_LIB_DEPENDS=	libpcsclite.so:devel/pcsc-lite
YUBIKEY_CMAKE_BOOL=	WITH_XC_YUBIKEY

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 1500000
OPTIONS_DEFAULT+=	YUBIKEY
.endif

.include <bsd.port.mk>
