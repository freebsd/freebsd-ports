# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	doublemetaphone
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PECL extension which implements the Double Metaphone algorithm

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-doublemetaphone

.include <bsd.port.mk>
