PORTNAME=	worker
PORTVERSION=	6.0.0
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}fm/${PORTNAME}fm/${PORTVERSION} \
		${WWW}downloads/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X11 file manager based on Directory Opus of AmigaOS
WWW=		http://www.boomerangsworld.de/cms/worker/

LICENSE=	GPLv2+

RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++20-lang localbase pkgconfig python:run \
		shebangfix tar:zst xorg
GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11 xinerama

SHEBANG_FILES=	${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/xeditor \
		${WRKSRC}/scripts/find_file_by_chksum.py

OPTIONS_DEFINE=	AVFS DBUS IMLIB2 INOTIFY LUA SSL XFT
OPTIONS_DEFAULT=	AVFS DBUS INOTIFY SSL XFT
OPTIONS_EXCLUDE_DragonFly=	AVFS

INOTIFY_DESC=	Monitor directory changes via libinotify
AVFS_DESC=	Use AVFS library to access archives
SSL_DESC=	SHA-256 checksum support via OpenSSL

AVFS_LIB_DEPENDS=	libavfs.so:filesystems/avfs
AVFS_CONFIGURE_OFF=	--without-avfs

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	--without-dbus

IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_CONFIGURE_OFF=	--disable-imlib

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CONFIGURE_OFF=	--disable-inotify

LUA_USES=		lua
LUA_CONFIGURE_OFF=	--disable-lua

SSL_USES=		ssl
SSL_CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
			OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

XFT_USE=		xorg=xft
XFT_CONFIGURE_OFF=	--disable-xft

post-patch:
	@${REINPLACE_CMD} -e '/#include <iomanip>/ { x; \
		s/^/#include <sstream>/; G; }' ${WRKSRC}/src/checksumming.cc

.include <bsd.port.mk>
