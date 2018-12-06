# Created by: Larry Rosenman <ler@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	textproc pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create/apply binary and text patches

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	limit:^1.*

.include <bsd.port.mk>
