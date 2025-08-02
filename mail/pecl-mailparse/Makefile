PORTNAME=	mailparse
DISTVERSION=	3.1.8
CATEGORIES=	mail www

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create and decode MIME messages
WWW=		https://pecl.php.net/package/mailparse

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl
USE_PHP=	mbstring:build

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 85
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/php_mailparse_mime.h \
		${WRKSRC}/php_mailparse_rfc822.c \
		${WRKSRC}/php_mailparse_rfc822.re
.endif

.include <bsd.port.post.mk>
