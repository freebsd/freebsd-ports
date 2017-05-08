# $FreeBSD$

PORTNAME=	oauth
PORTVERSION=	2.0.2
CATEGORIES=	net pear
PKGNAMESUFFIX=	2

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Php interface to the OAuth Protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

PORTSCOUT=	limit:^2.*

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USES=		php:pecl
IGNORE_WITH_PHP=	56
CONFLICTS=	pecl-oauth-1*

.include <bsd.port.mk>
