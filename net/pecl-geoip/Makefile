# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	geoip
PORTVERSION=	1.1.1
CATEGORIES=	net www

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Map IP address to geographic places

LICENSE=	PHP301

LIB_DEPENDS=	libGeoIP.so:net/GeoIP

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

USES=		php:pecl

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
