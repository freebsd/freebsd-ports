PORTNAME=	yaf
PORTVERSION=	3.3.5
CATEGORIES=	www

MAINTAINER=	sunpoet@freeBSD.org
COMMENT=	MVC framework written as a C PHP extension
WWW=		https://pecl.php.net/package/yaf \
		https://github.com/laruence/yaf

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		localbase php:pecl

CFLAGS+=	-DZEND_HOT=

.include <bsd.port.mk>
