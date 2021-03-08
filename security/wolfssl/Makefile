# $FreeBSD$

PORTNAME=	wolfssl
PORTVERSION=	4.7.0
CATEGORIES=	security devel
MASTER_SITES=	https://www.wolfssl.com/ \
		LOCAL/fox

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Embedded SSL C-Library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool zip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-certgen \
		--enable-des3 \
		--enable-dh \
		--enable-dsa \
		--enable-dtls \
		--enable-ecc \
		--enable-ipv6 \
		--enable-keygen \
		--enable-opensslall \
		--enable-opensslextra \
		--enable-ripemd \
		--enable-sessioncerts \
		--enable-sha512 \
		--enable-shared \
		--enable-sni \
		--enable-ssh \
		--enable-static \
		--enable-tls13 \
		--enable-tls13-draft18
TEST_TARGET=	check
CFLAGS+=	-DWOLFSSL_ALT_NAMES

OPTIONS_DEFINE=	DEBUG DOCS

DEBUG_CONFIGURE_ON=	--enable-debug

post-configure:
	@${REINPLACE_CMD} \
		-e 's|$${prefix}/cyassl/include|$${prefix}/include/cyassl|' \
		-e 's|$${prefix}/cyassl/lib|$${prefix}/lib/cyassl|' \
		-e '/^pkgconfigdir/s|(libdir)|&data|' \
		${WRKSRC}/Makefile

post-install-DEBUG-off:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwolfssl.so

.include <bsd.port.mk>
