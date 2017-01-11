# Created by: Larry Rosenman <ler@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdiff
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	textproc pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	dbaio@bsd.com.br
COMMENT=	PECL extension to create/apply binary and text patches

LICENSE=	PHP301

LIB_DEPENDS=	libxdiff.so:textproc/libxdiff

PORTSCOUT=	limit:^1.*

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
