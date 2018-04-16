# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	mod_memcache_block
PORTVERSION=	20120821
PORTREVISION=	1
CATEGORIES=	www
DIST_SUBDIR=	apache2

MAINTAINER=	gaod@hychen.org
COMMENT=	Apache 2.2 module to block IPs from lists stored in memcache

LIB_DEPENDS+=	libmemcached.so:databases/libmemcached

USE_GITHUB=	yes
GH_ACCOUNT=	netik
GH_TAGNAME=	7b1fcec

BROKEN=		Does not currently work with Apache 2.4+

USES=		apache:2.4+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=		${LOCALBASE}/include/libmemcached
AP_LIB=		${LOCALBASE}/lib -lmemcached

.include <bsd.port.mk>
