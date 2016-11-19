# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	timezonedb
PORTVERSION=	2016.9
CATEGORIES=	misc
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Timezone Database to be used with PHP date and time functions

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFIGURE_ARGS=	--enable-timezonedb
USES=		php:ext tar:tgz

.include <bsd.port.mk>
