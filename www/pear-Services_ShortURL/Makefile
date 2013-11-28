# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Services_ShortURL
PORTVERSION=	0.3.1
CATEGORIES=	www pear

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Abstract PHP5 interface for shortening and expanding short URLs

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

USE_PHP=	simplexml pcre spl
PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
