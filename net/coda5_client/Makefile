# New ports collection makefile for:	coda-client
# Date created:				Mon Oct  18 12:01:27 EDT 1999
# Whom:					???
#
# $FreeBSD$
#

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
PORTREVISION=	1

MAINTAINER=	coda@cs.cmu.edu
COMMENT=	Client programs for a replicated high-performance network file system

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

MASTERDIR=	${.CURDIR}/../coda5_server
PKGDIR=		${.CURDIR}

CODA_SUITE=	client

.include "${MASTERDIR}/Makefile"
