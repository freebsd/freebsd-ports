# New ports collection makefile for:	coda-server-6
# Date created:				9 september 2003
# Whom:					Tim Robbins

# $FreeBSD$

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
PKGNAMESUFFIX=	-${CODA_SUITE}
DISTNAME=	coda-${PORTVERSION}

MAINTAINER?=	tim@robbins.dropbear.id.au
COMMENT=	Server programs for a replicated high-performance network file system

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		lwp.2:${PORTSDIR}/devel/lwp \
		rpc2.4:${PORTSDIR}/devel/rpc2 \
		rvm.2:${PORTSDIR}/devel/rvm

CONFLICTS=	coda-server-5.*

ALL_TARGET=	coda
INSTALL_TARGET=	${CODA_SUITE}-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS?=	--sysconfdir=${PREFIX}/etc/rc.d

CODA_SUITE?=	server
CODA_VERSION?=	6.0.2

.include <bsd.port.pre.mk>

.if ${CODA_SUITE} == client
.if ${OSVERSION} < 501106
IGNORE=		"This version of FreeBSD lacks Coda 6.x kernel support"
.endif
.endif

.include <bsd.port.post.mk>
