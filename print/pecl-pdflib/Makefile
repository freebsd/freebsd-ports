# New ports collection makefile for:	pecl-pdflib
# Date created:			25 Jun 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	2.0
CATEGORIES=	print pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to create PDF on the fly

LIB_DEPENDS=	pdf.7:${PORTSDIR}/print/pdflib

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--with-pdflib=${LOCALBASE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/pdf.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
