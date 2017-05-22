# Created by: Larry Rosenman <ler@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	textproc pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

PORTSCOUT=	limit:^1.*

USES=		php:pecl
IGNORE_WITH_PHP=	70 71

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
