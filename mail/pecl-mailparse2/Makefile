# Created by: Thierry Thomas (<thierry@pompo.net>)
# $FreeBSD$

PORTNAME=	mailparse
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	mail www

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create and decode MIME messages

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP202

USES=		php:pecl
USE_PHP=	mbstring:build
IGNORE_WITH_PHP=	71 72 73

PORTSCOUT=	limit:^2.*

.include <bsd.port.mk>
