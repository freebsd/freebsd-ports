# New ports collection makefile for:	pecl-pdflib
# Date created:			25 Jun 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to create PDF on the fly

LIB_DEPENDS=	pdf.8:${PORTSDIR}/print/pdflib

USE_PHP=	gd
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
PHP_MODNAME=	pdf

CONFIGURE_ARGS=	--with-pdflib=${LOCALBASE}

post-extract:
	@${ECHO_CMD} "#define PHP_PDFLIB_VERSION \"${PORTVERSION}\"" > \
		${WRKSRC}/php_pdflib.h

.include <bsd.port.mk>
