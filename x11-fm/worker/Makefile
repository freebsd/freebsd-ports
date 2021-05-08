# Created by: Simon Dick <simond@irrelevant.org>

PORTNAME=	worker
PORTVERSION=	4.8.1
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/

MAINTAINER=	mp39590@gmail.com
COMMENT=	X11 file manager based on Directory Opus of AmigaOS

LICENSE=	GPLv2+

RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++14-lang localbase pkgconfig python:run \
		shebangfix tar:bzip2 xorg
GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11 xinerama

SHEBANG_FILES=	${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/xeditor \
		${WRKSRC}/scripts/find_file_by_chksum.py

OPTIONS_DEFINE=	AVFS DBUS INOTIFY LUA SSL XFT
OPTIONS_DEFAULT=	AVFS DBUS INOTIFY SSL XFT
OPTIONS_EXCLUDE_DragonFly=	AVFS

INOTIFY_DESC=	Monitor directory changes via libinotify
AVFS_DESC=	Use AVFS library to access archives
SSL_DESC=	SHA-256 checksum support via OpenSSL

AVFS_LIB_DEPENDS=	libavfs.so:sysutils/avfs
AVFS_CONFIGURE_OFF=	--without-avfs

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	--without-dbus

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CONFIGURE_OFF=	--disable-inotify

LUA_USES=		lua
LUA_CONFIGURE_OFF=	--disable-lua

SSL_USES=		ssl
SSL_CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

XFT_USE=		xorg=xft
XFT_CONFIGURE_OFF=	--disable-xft

.include <bsd.port.mk>
