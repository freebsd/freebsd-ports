# $FreeBSD$

PORTNAME=	megacmd
DISTVERSION=	1.4.0
DISTVERSIONSUFFIX=	_Linux
CATEGORIES=	net

MAINTAINER=	menelkir@itroll.org
COMMENT=	Command Line Interactive and Scriptable Application to access MEGA

LICENSE=	GPLv3 BSD2CLAUSE
LICENSE_COMB=	multi

LIB_DEPENDS=	libcares.so:dns/c-ares libcryptopp.so:security/cryptopp \
		libcurl.so:ftp/curl libsodium.so:security/libsodium \
		libuv.so:devel/libuv libpcre.so:devel/pcre

USES=		autoreconf libtool sqlite:3 readline shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	meganz
GH_PROJECT=	MEGAcmd sdk:sdk
GH_SUBDIR=	sdk:sdk
GH_TAGNAME=	v3.7.3c:sdk

USE_LDCONFIG=	yes

SHEBANG_FILES=	src/client/mega-lpwd \
		src/client/mega-permissions \
		src/client/mega-ls \
		src/client/mega-pwd \
		src/client/mega-deleteversions \
		src/client/mega-log \
		src/client/mega-session \
		src/client/mega-share \
		src/client/mega-quit \
		src/client/mega-reload \
		src/client/mega-find \
		src/client/mega-errorcode \
		src/client/mega-logout \
		src/client/mega-backup \
		src/client/mega-exclude \
		src/client/mega-confirmcancel \
		src/client/mega-transfers \
		src/client/mega-rm \
		src/client/mega-invite \
		src/client/mega-webdav \
		src/client/mega-cancel \
		src/client/mega-cp \
		src/client/mega-cd \
		src/client/mega-thumbnail \
		src/client/mega-attr \
		src/client/mega-login \
		src/client/mega-speedlimit \
		src/client/mega-get \
		src/client/mega-debug \
		src/client/mega-du \
		src/client/mega-ipc \
		src/client/mega-mv \
		src/client/mega-whoami \
		src/client/mega-https \
		src/client/mega-help \
		src/client/mega-showpcr \
		src/client/mega-lcd \
		src/client/mega-preview \
		src/client/mega-ftp \
		src/client/mega-put \
		src/client/mega-graphics \
		src/client/mega-mount \
		src/client/mega-import \
		src/client/mega-version \
		src/client/mega-confirm \
		src/client/mega-mkdir \
		src/client/mega-userattr \
		src/client/mega-signup \
		src/client/mega-passwd \
		src/client/mega-killsession \
		src/client/mega-sync \
		src/client/mega-users \
		src/client/mega-export \
		src/client/mega-cat \
		src/client/mega-mediainfo \
		src/client/mega-proxy \
		src/client/mega-df \
		src/client/mega-tree

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples \
		--disable-java --disable-php --disable-python \
		--disable-chat --without-freeimage \
		--without-termcap --without-ffmpeg --without-libraw \
		--without-libzen --without-libmediainfo \
		--enable-gcc-hardening \
		--with-cares=${LOCALBASE} --with-cryptopp=${LOCALBASE} \
		--with-curl=${LOCALBASE} --with-sodium=${LOCALBASE} \
		--with-sqlite=${LOCALBASE} --with-libuv=${LOCALBASE} \
		--with-zlib --with-readline=${LOCALBASE}

INSTALL_TARGET=	install-strip

CXXFLAGS+=	`pkgconf --cflags-only-other libcryptopp`

.include <bsd.port.mk>
