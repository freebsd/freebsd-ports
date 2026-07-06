PORTNAME=	xlswriter
PORTVERSION=	2.0.1
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient and fast xlsx file extension
WWW=		https://pecl.php.net/package/xlswriter \
		https://github.com/viest/php-ext-xlswriter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxlsxwriter.so:math/libxlsxwriter

#USES=		localbase php:pecl ssl
USES=		php:pecl ssl
IGNORE_WITH_PHP=	86

CFLAGS+=	-I${LOCALBASE}/include/minizip
CONFIGURE_ARGS=	 --with-libxlsxwriter=${LOCALBASE} \
		 --with-openssl=${OPENSSLBASE}

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/library/libxlsxwriter/

.include <bsd.port.mk>
