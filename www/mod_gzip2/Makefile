# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 13 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_gzip
PORTVERSION=	1.3.19.2a
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-gzip
EXTRACT_SUFX=	.tgz

MAINTAINER=	sysadmin@alexdupre.com

BUILD_DEPENDS=	${APXS}:${APACHE_PORT}
RUN_DEPENDS=	${APXS}:${APACHE_PORT}

APXS?=		${LOCALBASE}/sbin/apxs
APACHE_PORT?=	${PORTSDIR}/www/apache13

ALL_TARGET=	build

.include <bsd.port.mk>
