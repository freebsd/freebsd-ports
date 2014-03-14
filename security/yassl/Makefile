# $FreeBSD$

PORTNAME=	cyassl
PORTVERSION=	2.9.0
CATEGORIES=	security devel
MASTER_SITES=	http://www.yassl.com/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Embedded SSL C-Library

LICENSE=	GPLv2

USES=		zip
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-shared --enable-static \
		--enable-dtls --enable-opensslextra --enable-ipv6 \
		--enable-dsa --enable-ecc --enable-sni
USE_LDCONFIG=	yes
PORTDOCS=	*

post-configure:
	@${REINPLACE_CMD} \
		-e 's|$${prefix}/cyassl/include|$${prefix}/include/cyassl|' \
		-e 's|$${prefix}/cyassl/lib|$${prefix}/lib/cyassl|' \
		${WRKSRC}/Makefile
	# i386 assembly is broken: do not use
	@${REINPLACE_CMD} -e 's/(TFM_X86)/(TFM_X86_BROKEN)/' \
		${WRKSRC}/ctaocrypt/src/asm.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcyassl.so

.include <bsd.port.mk>
