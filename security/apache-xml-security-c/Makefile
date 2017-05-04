# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	xml-security-c
PORTVERSION=	1.7.3
CATEGORIES=	security
MASTER_SITES=	APACHE/santuario/c-library
PKGNAMEPREFIX=	apache-

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Apache XML security libraries - C++ version

LICENSE=	APACHE20

LIB_DEPENDS+=	libxerces-c.so.3:textproc/xerces-c3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
USES=		gmake libtool tar:bzip2 ssl
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}

BROKEN_SSL=	openssl-devel
BROKEN_SSL_REASON_openssl-devel=	field has incomplete type HMAC_CTX (aka hmac_ctx_st)

.include <bsd.port.mk>
