# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Services_GeoNames
PORTVERSION=	1.0.1
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PHP5 Interface to the GeoNames Public API

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/HTTP/Request2.php:${PORTSDIR}/www/pear-HTTP_Request2

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
