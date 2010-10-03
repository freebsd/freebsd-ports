# New ports collection makefile for:	0W-httpd
# Date created:				17 March 2005
# Whom:					Vsevolod Stakhov
#
# $FreeBSD$
#

PORTNAME=	zerowait
PORTVERSION=	0.8d
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.0w.ru/httpd/ \
		http://mirror.mcx2.org/
PKGNAMESUFFIX=	-httpd
DISTNAME=	0W-httpd-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Lightweight and fast http server

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	0W-httpd
ALL_TARGET=	#none

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --owner=${WWWOWN} --group=${WWWGRP}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

.include <bsd.port.mk>
