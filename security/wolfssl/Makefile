# $FreeBSD$

PORTNAME=	wolfssl
PORTVERSION=	4.5.0
CATEGORIES=	security devel
MASTER_SITES=	https://www.wolfssl.com/ \
		LOCAL/fox
MAINTAINER=	fox@FreeBSD.org
COMMENT=	Embedded SSL C-Library

PATCH_SITES=	https://github.com/wolfSSL/wolfssl/commit/
PATCHFILES=	e9b1ceae7e1daac6206d399e30c04bd51e3f8c7f.patch:-p1

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool zip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-dh \
		--enable-dsa \
		--enable-dtls \
		--enable-ecc \
		--enable-ipv6 \
		--enable-keygen \
		--enable-opensslextra \
		--enable-ripemd \
		--enable-sha512 \
		--enable-shared \
		--enable-sni \
		--enable-ssh \
		--enable-static \
		--enable-tls13 \
		--enable-tls13-draft18 \
		--enable-tls13-draft22 \
		--enable-tls13-draft23 \
		--enable-tls13-draft26 \
		--enable-tls13-draft28
TEST_TARGET=	check
PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} \
		-e 's|$${prefix}/cyassl/include|$${prefix}/include/cyassl|' \
		-e 's|$${prefix}/cyassl/lib|$${prefix}/lib/cyassl|' \
		-e '/^pkgconfigdir/s|(libdir)|&data|' \
		${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libwolfssl.so

.include <bsd.port.mk>
