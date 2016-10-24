# $FreeBSD$

PORTNAME=	stats
PORTVERSION=	2.0.3
CATEGORIES=	math textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
PKGNAMESUFFIX=	2
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	PECL extension with routines for statistical computation

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^2.*

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	56
CONFLICTS=	pecl-stats-1*

.include <bsd.port.mk>
