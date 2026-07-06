PORTNAME=	oauth
DISTVERSION=	2.0.12
CATEGORIES=	net pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}pecl-

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Php interface to the OAuth Protocol
WWW=		https://github.com/php/pecl-web_services-oauth/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

USES=		localbase:ldflags php:ext
USE_GITHUB=	yes
GH_ACCOUNT=	php
GH_PROJECT=	pecl-web_services-oauth

CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

PORTSCOUT=	limit:^2.*

.include <bsd.port.pre.mk>

.if ${PHP_VER} >= 86
post-patch:
	@${REINPLACE_CMD} -e 's|XtOffsetOf|offsetof|' \
		${WRKSRC}/*.c ${WRKSRC}/*.h
.endif

.include <bsd.port.post.mk>
