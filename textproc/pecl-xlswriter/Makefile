PORTNAME=	xlswriter
PORTVERSION=	3.0.0
CATEGORIES=	textproc

PATCH_SITES=	https://github.com/viest/php-ext-xlswriter/commit/
PATCHFILES=	895ae9c8cf91acb9fc7466dc4b00a0534b05aa94.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Efficient and fast xlsx file extension
WWW=		https://pecl.php.net/package/xlswriter \
		https://github.com/viest/php-ext-xlswriter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxlsxwriter.so:math/libxlsxwriter

USES=		php:pecl ssl

CFLAGS+=	-I${LOCALBASE}/include/minizip
CONFIGURE_ARGS=	 --with-libxlsxwriter=${LOCALBASE} \
		 --with-openssl=${OPENSSLBASE}

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/library/libxlsxwriter/

.include <bsd.port.mk>
