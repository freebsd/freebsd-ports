PORTNAME=	stomp
PORTVERSION=	2.0.2
CATEGORIES=	net-im pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension of stomp client

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Requires php 7.4 which is set to expire on 2022-11-29
EXPIRATION_DATE=2022-11-28

USES=		php:pecl
IGNORE_WITH_PHP=	80 81
CONFLICTS=	pecl-stomp-1*

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
