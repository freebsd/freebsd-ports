# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdflib
PORTVERSION=	3.0.4
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PECL extension to create PDF on the fly

LICENSE=	PHP30

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libpdf.so:print/pdflib

USES=		php:ext
USE_PHP=	gd:build
PHP_MODNAME=	pdf
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--with-pdflib=${LOCALBASE}

.include <bsd.port.mk>
