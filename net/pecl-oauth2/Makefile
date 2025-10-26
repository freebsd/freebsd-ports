PORTNAME=	oauth
DISTVERSION=	2.0.10
CATEGORIES=	net pear

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Php interface to the OAuth Protocol
WWW=		https://pecl.php.net/package/oauth

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

USES=		localbase:ldflags php:pecl

CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
