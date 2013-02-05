# $FreeBSD$

PORTNAME=	cyassl
PORTVERSION=	2.5.0
CATEGORIES=	security devel
MASTER_SITES=	http://www.yassl.com/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A embedded SSL C-Library

LICENSE=	GPLv2

USE_ZIP=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--enable-shared --enable-static \
		--enable-dtls --enable-opensslExtra --enable-ipv6
USE_LDCONFIG=	yes
PORTDOCS=	*

post-configure:
	${REINPLACE_CMD} \
		-e 's|$${prefix}/cyassl/include|$${prefix}/include/cyassl|' \
		-e 's|$${prefix}/cyassl/lib|$${prefix}/lib/cyassl|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
