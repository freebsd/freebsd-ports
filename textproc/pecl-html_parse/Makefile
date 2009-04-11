# New ports collection makefile for:	pecl-html_parse
# Date created:			21 December 2007
# Whom:				Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	html_parse
PORTVERSION=	1.0.0
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension for the ekhtml library

BUILD_DEPENDS=	${LOCALBASE}/lib/libekhtml.a:${PORTSDIR}/textproc/ekhtml
RUN_DEPENDS=	${LOCALBASE}/lib/libekhtml.a:${PORTSDIR}/textproc/ekhtml

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-html_parse

.include <bsd.port.mk>
