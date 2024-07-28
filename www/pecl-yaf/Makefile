PORTNAME=	yaf
PORTVERSION=	3.3.6
CATEGORIES=	www

MAINTAINER=	sunpoet@freeBSD.org
COMMENT=	MVC framework written as a C PHP extension
WWW=		https://pecl.php.net/package/yaf \
		https://github.com/laruence/yaf

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase php:pecl
IGNORE_WITH_PHP=	84

CFLAGS+=	-DZEND_HOT=

.include <bsd.port.mk>
