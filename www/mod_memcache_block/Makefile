PORTNAME=	mod_memcache_block
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	www
DIST_SUBDIR=	apache2

MAINTAINER=	gaod@hychen.org
COMMENT=	Apache 2.2 module to block IPs from lists stored in memcache
WWW=		https://github.com/netik/mod_memcache_block

LIB_DEPENDS+=	libmemcached.so:databases/libmemcached

USE_GITHUB=	yes
GH_ACCOUNT=	gaod

USES=		apache
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=		${LOCALBASE}/include/libmemcached
AP_LIB=		${LOCALBASE}/lib -lmemcached

.include <bsd.port.mk>
