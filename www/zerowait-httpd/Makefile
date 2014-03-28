# Created by: Vsevolod Stakhov
# $FreeBSD$

PORTNAME=	zerowait
PORTVERSION=	0.8d
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://mirror.mcx2.org/
PKGNAMESUFFIX=	-httpd
DISTNAME=	0W-httpd-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Lightweight and fast http server

USES=		gmake
USE_OPENSSL=	yes
USE_RC_SUBR=	0W-httpd
ALL_TARGET=	#none

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --owner=${WWWOWN} --group=${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

NO_STAGE=	yes
.include <bsd.port.mk>
