# New ports collection makefile for:	coda-client
# Date created:				Mon Oct  18 12:01:27 EDT 1999
# Whom:					???
#
# $FreeBSD$
#

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
PORTREVISION=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client programs for a replicated high-performance network file system

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

MASTERDIR=	${.CURDIR}/../coda5_server
PKGDIR=		${.CURDIR}
LATEST_LINK=	coda5-client

CODA_SUITE=	client

.include "${MASTERDIR}/Makefile"
