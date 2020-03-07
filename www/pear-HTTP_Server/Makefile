# Created by: Gerrit Beine (<tux@pinguru.net>)
# $FreeBSD$

PORTNAME=	HTTP_Server
PORTVERSION=	0.4.1
CATEGORIES=	www devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	HTTP server class

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:www/pear-HTTP@${PHP_FLAVOR} \
		${PEARDIR}/Net/Server.php:net/pear-Net_Server@${PHP_FLAVOR}
RUN_DEPENDS=	${PEARDIR}/HTTP.php:www/pear-HTTP@${PHP_FLAVOR} \
		${PEARDIR}/Net/Server.php:net/pear-Net_Server@${PHP_FLAVOR}

USES=		pear

.include <bsd.port.mk>
