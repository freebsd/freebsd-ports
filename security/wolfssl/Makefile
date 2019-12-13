# $FreeBSD$

PORTNAME=	wolfssl
PORTVERSION=	4.2.0
CATEGORIES=	security devel
MASTER_SITES=	https://www.wolfssl.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embedded SSL C-Library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	fails to package: pkg-static: Unable to access file libwolfssl.so.3: No such file or directory
BROKEN_mips64=	fails to package: pkg-static: Unable to access file libwolfssl.so.3: No such file or directory

USES=		libtool zip
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-shared --enable-static \
		--enable-dtls --enable-opensslextra --enable-ipv6 \
		--enable-dsa --enable-dh --enable-ecc --enable-sni \
		--enable-ripemd --enable-sha512 --enable-opensslcoexist\
		--enable-tls13 --enable-tls13-draft18\
		--enable-tls13-draft22 --enable-tls13-draft23\
		--enable-tls13-draft26 --enable-tls13-draft28\
		--enable-ssh --enable-keygen
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
