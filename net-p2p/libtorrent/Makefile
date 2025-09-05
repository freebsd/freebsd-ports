PORTNAME=	libtorrent
DISTVERSION=	0.16.0
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/rakshasa/rtorrent/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	BitTorrent Library written in C++
WWW=		https://github.com/rakshasa/libtorrent

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl
TEST_DEPENDS=	cppunit>0:devel/cppunit

USES=		compiler:c++17-lang cpe libtool localbase:ldflags pathfix \
		pkgconfig ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I ${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

# This makes sure that /usr/local/lib appears before /usr/lib when
# linking libtorrent to avoid linking with base's libcrypto.
MAKE_ARGS=	LDFLAGS="${LDFLAGS}"

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

TESTING_UNSAFE=	https://github.com/rakshasa/libtorrent/issues/292

OPTIONS_DEFINE=		KQUEUE
OPTIONS_DEFAULT=	KQUEUE

KQUEUE_DESC=		Use kqueue(2) support
KQUEUE_CONFIGURE_WITH=	kqueue

.include <bsd.port.mk>
