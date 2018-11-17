# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GUPnP wrapper extension

LICENSE=	PHP301

BROKEN=		does not build with latest gssdp and gupnp
DEPRECATED=	does not build with latest gssdp and gupnp
EXPIRATION_DATE=2018-11-30

LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp

IGNORE_WITH_PHP=70 71 72 73
USES=		php:pecl pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's| -ldl||g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
