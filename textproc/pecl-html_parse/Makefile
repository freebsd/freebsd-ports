# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	html_parse
PORTVERSION=	1.0.0
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension for the ekhtml library

LICENSE=	PHP30

BUILD_DEPENDS=	${LOCALBASE}/lib/libekhtml.a:textproc/ekhtml
RUN_DEPENDS=	${LOCALBASE}/lib/libekhtml.a:textproc/ekhtml

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56 70

CONFIGURE_ARGS=	--enable-html_parse

.include <bsd.port.mk>
