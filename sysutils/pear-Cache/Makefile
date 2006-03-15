# Ports collection makefile for:  pear-Cache
# Date created:			  5 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	Cache
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	sysutils www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR framework for caching of arbitrary data

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		Cache.php Cache/Application.php Cache/Container.php	\
		Cache/Container/db.php Cache/Container/dbx.php		\
		Cache/Container/file.php Cache/Container/mdb.php	\
		Cache/Container/mdb_cache_schema.xml			\
		Cache/Container/msession.php Cache/Container/phplib.php	\
		Cache/Container/shm.php Cache/Container/trifile.php	\
		Cache/Error.php Cache/Function.php Cache/Graphics.php	\
		Cache/HTTP_Request.php Cache/Output.php			\
		Cache/OutputCompression.php

post-extract:
	@${MKDIR} ${WRKSRC}/Cache
	@${MV} ${WRKSRC}/Container ${WRKSRC}/Cache
	@${MV} ${WRKSRC}/*.php ${WRKSRC}/Cache
	@${MV} ${WRKSRC}/Cache/Cache.php ${WRKSRC}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
