# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mogilefs
PORTVERSION=	0.9.2
PORTREVISION=	2
CATEGORIES=	sysutils pear

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP client library to communicate with the MogileFS storage

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libneon.so:www/neon

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

post-extract:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
