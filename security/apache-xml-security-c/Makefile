# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	xml-security-c
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	APACHE/santuario/c-library
PKGNAMEPREFIX=	apache-

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Apache XML security libraries - C++ version

LICENSE=	APACHE20

USE_OPENSSL=	yes

LIB_DEPENDS+=	libxerces-c.so.3:textproc/xerces-c3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-xerces=${LOCALBASE}
USES=		gmake libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
