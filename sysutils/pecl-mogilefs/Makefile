# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mogilefs
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	sysutils pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	PHP client library to communicate with the MogileFS storage

LICENSE=	BSD

LIB_DEPENDS=	libneon.so:www/neon

USES=		php:ext
IGNORE_WITH_PHP=	70

post-extract:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/config.m4

.include <bsd.port.mk>
