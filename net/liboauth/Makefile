# $FreeBSD$

PORTNAME=	liboauth
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C library implementing the OAuth Core standard

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

USE_OPENSSL=	yes
USES=		pkgconfig
USE_LDCONFIG=	yes

MAN3=		oauth.3

post-patch:
	@${REINPLACE_CMD} -e '/PC_REQ=/s/ libcrypto//' ${WRKSRC}/configure

.include <bsd.port.mk>
