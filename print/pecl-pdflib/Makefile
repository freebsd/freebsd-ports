PORTNAME=	pdflib
PORTVERSION=	4.1.4
PORTREVISION=	1
CATEGORIES=	print pear

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PECL extension to create PDF on the fly

LICENSE=	PDFlib
LICENSE_NAME=	PDFlib GmbH General License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	none

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

LIB_DEPENDS=	libpdf.so:print/pdflib

USES=		php:pecl

USE_PHP=	gd:build
IGNORE_WITH_PHP=80 81 82
PHP_MODNAME=	pdf

CONFIGURE_ARGS=	--with-pdflib=${LOCALBASE}

.include <bsd.port.mk>
