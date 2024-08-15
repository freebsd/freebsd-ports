PORTNAME=	xlswriter
PORTVERSION=	1.5.5
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient and fast xlsx file extension
WWW=		https://pecl.php.net/package/xlswriter \
		https://github.com/viest/php-ext-xlswriter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase php:pecl ssl

LIB_DEPENDS=	libxlsxio_read.so:textproc/xlsxio

CONFIGURE_ARGS=	 --with-libxlsxio=${LOCALBASE} \
		 --with-openssl=${OPENSSLBASE}

.include <bsd.port.mk>
