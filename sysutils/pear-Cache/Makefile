# Ports collection makefile for:  pear-Cache
# Date created:			  5 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	Cache
PORTVERSION=	1.5.4
CATEGORIES=	sysutils www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR framework for caching of arbitrary data

BUILD_DEPENDS=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Cache
FILES=		Application.php Cache.php Container.php Container/db.php	\
		Container/dbx.php Container/file.php Container/mdb.php		\
		Container/mdb_cache_schema.xml Container/msession.php		\
		Container/phplib.php Container/shm.php Container/trifile.php	\
		Error.php Function.php Graphics.php HTTP_Request.php Output.php	\
		OutputCompression.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
