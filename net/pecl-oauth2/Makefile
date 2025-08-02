PORTNAME=	oauth
DISTVERSION=	2.0.7
CATEGORIES=	net pear

# https://github.com/php/pecl-web_services-oauth/pull/30
PATCH_SITES=	https://github.com/php/pecl-web_services-oauth/commit/
PATCHFILES=	e7f262becf3feb65c8195fff4591d9dbd8acbace.patch:-p1

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Php interface to the OAuth Protocol
WWW=		https://pecl.php.net/package/oauth

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre

USES=		localbase:ldflags php:pecl

CONFIGURE_ARGS+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

CONFLICTS=	pecl-oauth-1*

PORTSCOUT=	limit:^2.*

.include <bsd.port.pre.mk>

.if ${PHP_VER} >= 85
.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/php_oauth.h
.endif

.include <bsd.port.post.mk>
