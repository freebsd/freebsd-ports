# New ports collection makefile for:	liboauth
# Date created:		30 October 2010
# Whom:			johans
#
# $FreeBSD$
#

PORTNAME=	liboauth
PORTVERSION=	1.0.0
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	C library implementing the OAuth Core standard

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

USE_OPENSSL=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

MAN3=		oauth.3

post-patch:
	@${REINPLACE_CMD} -e '/PC_REQ=/s/ libcrypto//' ${WRKSRC}/configure

.include <bsd.port.mk>
