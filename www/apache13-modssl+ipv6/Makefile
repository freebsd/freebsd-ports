# New ports collection makefile for:	apache13-modssl+ipv6
# Date created:		04.Nov 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

CATEGORIES=	www security ipv6

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The Apache 1.3 webserver with SSL/TLS and IPv6 functionality

WITH_APACHE_IPV6=yes
MASTERDIR?=	${.CURDIR}/../apache13-modssl

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
