# New ports collection makefile for:	coda-server-6
# Date created:				9 september 2003
# Whom:					Tim Robbins

# $FreeBSD$

PORTNAME=	coda
PORTVERSION=	${CODA_VERSION}
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
PKGNAMESUFFIX=	-${CODA_SUITE}
DISTNAME=	coda-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT=	Server programs for a replicated high-performance network file system

LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp \
		rpc2.6:${PORTSDIR}/devel/rpc2 \
		rvm.3:${PORTSDIR}/devel/rvm

CONFLICTS=	coda-server-5.*

ALL_TARGET=	coda
INSTALL_TARGET=	${CODA_SUITE}-install

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CODA_SUITE?=	server
CODA_VERSION?=	6.0.7

.if ${CODA_SUITE} == server
MAN5=		vicetab.5	passwd.coda.5
MAN8=		pdbtool.8	auth2.8	initpw.8 norton.8
.else
MAN1=	clog.1	cpasswd.1	ctokens.1	cunlog.1 \
	repair.1	cfs.1	cmon.1	coda_replay.1 \
	hoard.1	spy.1
MAN8=	au.8	venus.8
.endif

.include <bsd.port.pre.mk>

.if ${CODA_SUITE} == client
.if ${OSVERSION} < 501106
IGNORE=		lacks kernel support on this version of FreeBSD
.endif
.if ${OSVERSION} >= 600000
IGNORE=		makes a kernel panic on this version of FreeBSD
.endif
.endif

.if ${OSVERSION} > 505000
BROKEN=		does not compile
.endif

DEPRECATED=	compiles neither on 5-STABLE nor 6-STABLE; current version is quite old
EXPIRATION_DATE=	2006-10-11

.include <bsd.port.post.mk>
