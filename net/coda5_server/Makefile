# New ports collection makefile for:	coda-server
# Date created:				Mon Oct 18 12:01:28 EDT 1999
# Whom:					???#
#
# $FreeBSD$
#

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
PKGNAMESUFFIX=	-${CODA_SUITE}
DISTNAME=	coda-${PORTVERSION}

MAINTAINER?=	coda@cs.cmu.edu
COMMENT?=	Server programs for a replicated high-performance network file system

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		lwp.2:${PORTSDIR}/devel/lwp \
		rpc2.6:${PORTSDIR}/devel/rpc2 \
		rvm.3:${PORTSDIR}/devel/rvm

ALL_TARGET=	coda
INSTALL_TARGET=	${CODA_SUITE}-install

LATEST_LINK?=	coda5-server
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS?=	--sysconfdir=${PREFIX}/etc/rc.d

CODA_SUITE?=	server
CODA_VERSION?=	5.3.20

.include <bsd.port.mk>
