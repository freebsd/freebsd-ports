# New ports collection makefile for:	coda6_client
# Date created:				9 September 2003
# Whom:					Tim Robbins <tim@robbins.dropbear.id.au>
#
# $FreeBSD$

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
PORTREVISION=	1

COMMENT=	Client programs for a replicated high-performance network file system

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

MASTERDIR=	${.CURDIR}/../coda6_server
PKGDIR=		${.CURDIR}

CODA_SUITE=	client

.include "${MASTERDIR}/Makefile"
