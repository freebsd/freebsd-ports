# New ports collection makefile for:	coda-server
# Date created:				Mon Oct 18 12:01:28 EDT 1999
# Whom:					???#
#
# $FreeBSD$
#

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
PKGNAMESUFFIX=	-${CODA_SUITE}
DISTNAME=	coda-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	coda@cs.cmu.edu

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm \
		lwp.1:${PORTSDIR}/devel/lwp \
		rpc2.2:${PORTSDIR}/devel/rpc2 \
		rvm.1:${PORTSDIR}/devel/rvm

ALL_TARGET=	coda
INSTALL_TARGET=	${CODA_SUITE}-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS?=	--sysconfdir=${PREFIX}/etc/rc.d

CODA_SUITE?=	server
CODA_VERSION?=	5.3.8

.include <bsd.port.mk>
