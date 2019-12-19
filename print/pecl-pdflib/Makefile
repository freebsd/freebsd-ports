# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdflib
PORTVERSION=	4.1.4
CATEGORIES=	print pear

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PECL extension to create PDF on the fly

LIB_DEPENDS=	libpdf.so:print/pdflib

USES=		php:pecl

LICENSE_NAME=	PDFlib GmbH General License
LICENSE_PERM=	none
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_PHP=	gd:build
PHP_MODNAME=	pdf

CONFIGURE_ARGS=	--with-pdflib=${LOCALBASE}

.include <bsd.port.mk>
