PORTNAME=	pan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.164
CATEGORIES=	news gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Threaded GTK newsreader based on Agent for Windows
WWW=		https://gitlab.gnome.org/GNOME/pan/-/blob/master/README.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmime-3.0.so:mail/gmime30 \
		libenchant-2.so:textproc/enchant2 \
		libp11-kit.so:security/p11-kit

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools:build \
		gnome iconv pkgconfig tar:bzip2
USE_GNOME=	gtk30

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	GNOME

CMAKE_ON=	WANT_GMIME_CRYPTO

OPTIONS_DEFINE=		DBUS DOCS GNOME_KEYRING GNUTLS GSPELL NLS \
			NOTIFY WEBKITGTK
OPTIONS_DEFAULT=	DBUS GNOME_KEYRING GNUTLS GSPELL NOTIFY
OPTIONS_SUB=		yes

DBUS_DESC=	DBus support
GNOME_KEYRING_DESC=	Credential storage via libsecret
GSPELL_DESC=	Spellcheck via GSpell
NOTIFY_DESC=	Notification support
WEBKITGTK_DESC=	WebKitGTK support (experimental, broken)

DBUS_CMAKE_BOOL=	WANT_DBUS
DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus

DOCS_CMAKE_BOOL=	ENABLE_MANUAL
DOCS_BUILD_DEPENDS=	itstool:textproc/itstool

GNOME_KEYRING_CMAKE_BOOL=	WANT_GKR
GNOME_KEYRING_LIB_DEPENDS=	libsecret-1.so:security/libsecret \
				libgcr-base-3.so:security/gcr3

GNUTLS_CMAKE_BOOL=	WANT_GNUTLS
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

GSPELL_CMAKE_BOOL=	WANT_GSPELL
GSPELL_LIB_DEPENDS=	libgspell-1.so:textproc/gspell

NOTIFY_CMAKE_BOOL=	WANT_NOTIFY
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify

WEBKITGTK_CMAKE_BOOL=	WANT_WEBKIT
WEBKITGTK_LIB_DEPENDS=	libwebkitgtk-6.0.so:www/webkit2-gtk

.include <bsd.port.mk>
