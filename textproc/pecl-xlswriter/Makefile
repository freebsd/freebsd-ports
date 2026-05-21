PORTNAME=	xlswriter
PORTVERSION=	2.0.0
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient and fast xlsx file extension
WWW=		https://pecl.php.net/package/xlswriter \
		https://github.com/viest/php-ext-xlswriter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:pecl ssl

CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
