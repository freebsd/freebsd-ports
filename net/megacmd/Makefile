PORTNAME=	megacmd
DISTVERSION=	1.6.3
PORTREVISION=	1
DISTVERSIONSUFFIX=	_Linux
CATEGORIES=	net

MAINTAINER=	kikadf.01@gmail.com
COMMENT=	Command Line Interactive and Scriptable Application to access MEGA
WWW=		https://mega.nz/cm

LICENSE=	GPLv3 BSD2CLAUSE
LICENSE_COMB=	multi

LIB_DEPENDS=	libcares.so:dns/c-ares libcryptopp.so:security/cryptopp \
		libcurl.so:ftp/curl libsodium.so:security/libsodium \
		libuv.so:devel/libuv libpcre.so:devel/pcre

USES=		autoreconf libtool sqlite:3 readline shebangfix ssl pathfix

USE_GITHUB=	yes
GH_ACCOUNT=	meganz
GH_PROJECT=	MEGAcmd sdk:sdk
GH_SUBDIR=	sdk:sdk
GH_TAGNAME=	v4.17.1d:sdk

USE_LDCONFIG=	yes

SHEBANG_FILES=	src/client/mega-*
bash_CMD=	${SH}

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

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
