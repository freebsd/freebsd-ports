# Created by: Vsevolod Stakhov
# $FreeBSD$

PORTNAME=	zerowait
PORTVERSION=	0.8d
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://BSDforge.com/projects/source/www/zerowait-httpd/
PKGNAMESUFFIX=	-httpd
DISTNAME=	0W-httpd-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lightweight and fast http server

LICENSE=	BSD3CLAUSE

USES=		gmake ssl
USE_RC_SUBR=	0W-httpd
ALL_TARGET=	#none

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --owner=${WWWOWN} --group=${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_FILES=	pkg-deinstall

.include <bsd.port.mk>
