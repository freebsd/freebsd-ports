# New ports collection makefile for:	lighttpd-mysql
# Date created:		11.Apr 2010
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

CATEGORIES=	www
PKGNAMESUFFIX=	-mysqlauth

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../lighttpd

WITH_MYSQL=	yes

EXTRA_PATCHES+=	${.CURDIR}/files/patch-src_http_auth.c

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
