# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	mod_memcache_block
PORTVERSION=	20120821
CATEGORIES=	www
MASTER_SITES=	https://github.com/netik/mod_memcache_block/tarball/${GITVERSION}/
DISTNAME=	mod_memcache_block-${GITVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	gaod@hychen.org
COMMENT=	An Apache 2 module to block ip from lists stored in memcache

LIB_DEPENDS+=	memcached:${PORTSDIR}/databases/libmemcached

FETCH_ARGS=	-Fpr
GITVERSION=	7b1fcec
WRKSRC=		${WRKDIR}/netik-${DISTNAME}
LATEST_LINK=	mod_memcache_block

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC=		${LOCALBASE}/include/libmemcached
AP_LIB=		${LOCALBASE}/lib -lmemcached

NO_STAGE=	yes
.include <bsd.port.mk>
