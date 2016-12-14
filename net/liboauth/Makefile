# $FreeBSD$

PORTNAME=	liboauth
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library implementing the OAuth Core standard

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
INSTALL_TARGET=	install-strip

USE_OPENSSL=	yes
USES=		pkgconfig libtool
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/PC_REQ=/s/ libcrypto//' ${WRKSRC}/configure

.include <bsd.port.mk>
