# $FreeBSD$

PORTNAME=	oauth
PORTVERSION=	2.0.2
CATEGORIES=	net pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Php interface to the OAuth Protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_WITH_PHP=	56

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		php:pecl

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

CONFLICTS=	pecl-oauth-1*

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
