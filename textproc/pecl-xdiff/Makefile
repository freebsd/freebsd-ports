# Created by: Larry Rosenman <ler@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	textproc pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301

IGNORE_WITH_PHP=	70 71 72

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

USES=		php:pecl

LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	limit:^1.*

.include <bsd.port.mk>
