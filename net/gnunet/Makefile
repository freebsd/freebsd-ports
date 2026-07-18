PORTNAME=	gnunet
DISTVERSION=	0.27.0
CATEGORIES=	net
MASTER_SITES=	GNU

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Alternative network stack for building secure, decentralized and privacy-preserving distributed applications.
WWW=		https://www.gnunet.org/en/

LICENSE=	GPLv3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libcurl.so:ftp/curl \
		libmicrohttpd.so:www/libmicrohttpd \
		libjansson.so:devel/jansson \
		libunistring.so:devel/libunistring \
		libgcrypt.so:security/libgcrypt \
		libgnutls.so:security/gnutls \
		libsodium.so:security/libsodium \
		libidn2.so:dns/libidn2 \
		libgmp.so:math/gmp \
		libpq.so:databases/postgresql18-client

# RUN_DEPENDS=

USES=		compiler:c11 cpe desktop-file-utils iconv makeinfo meson pkgconfig \
		shebangfix sqlite tar
EXTRACT_SUFX=	.tar.gz

CPE_VENDOR=	gnu

CONFIGURE_ENV=	LIBRARY_PATH=$(PREFIX)/lib
MESON_ARGS+=    --libdir=$(PREFIX)/lib

SHEBANG_FILES=	scripts/netjail/topo.sh \
		scripts/netjail/netjail_stop.sh \
		scripts/netjail/netjail_core.sh \
		scripts/netjail/netjail_test_master.sh \
		scripts/netjail/netjail_exec.sh \
		scripts/netjail/netjail_start_new.sh \
		scripts/netjail/netjail_start.sh

post-patch:
	${REINPLACE_CMD} s+%%PREFIX%%+$(PREFIX)+ ${WRKSRC}/meson.build

.include <bsd.port.mk>
