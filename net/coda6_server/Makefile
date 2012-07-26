# New ports collection makefile for:	coda-server-6
# Date created:				9 september 2003
# Whom:					Tim Robbins

# $FreeBSD$

PORTNAME=	coda
PORTVERSION=	6.9.4
PORTREVISION?=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/src/ \
		ftp://ftp.planetmirror.com/pub/coda/src/ \
		ftp://ftp.nctu.edu.tw/mirror/Coda/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/
PKGNAMESUFFIX=	-${CODA_SUITE}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Server programs for a replicated high-performance network file system

LIB_DEPENDS=	lwp.2:${PORTSDIR}/devel/lwp \
		rpc2.9:${PORTSDIR}/devel/rpc2 \
		rvmlwp.3:${PORTSDIR}/devel/rvm

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	yes

CONFIGURE_ARGS+=	--enable-${CODA_SUITE}

CODA_SUITE?=	server

.if ${CODA_SUITE} == server
CONFLICTS=	openafs-[0-9]*

MAN5=	backuplogs.5 \
	dumpfile.5 \
	dumplist.5 \
	maxgroupid.5 \
	passwd.coda.5 \
	servers.5 \
	vicetab.5 \
	volumelist.5 \
	vrdb.5
MAN8=	auth2.8 \
	backup.8 \
	bldvldb.sh.8 \
	codasrv.8 \
	createvol_rep.8 \
	initpw.8 \
	merge.8 \
	norton.8 \
	pdbtool.8 \
	purgevol_rep.8 \
	readdump.8 \
	startserver.8 \
	updateclnt.8 \
	updatesrv.8 \
	vice-setup.8 \
	volutil.8
.else
MAN1=	au.1 \
	cfs.1 \
	clog.1 \
	cmon.1 \
	coda_replay.1 \
	cpasswd.1 \
	ctokens.1 \
	cunlog.1 \
	hoard.1 \
	mkcodabf.1 \
	repair.1 \
	spy.1
MAN8=	venus-setup.8 \
	venus.8 \
	volmunge.8 \
	vutil.8
.endif

.include <bsd.port.pre.mk>

.if ${CODA_SUITE} == client
# this needs testing with the new version (6.1.1)
#IGNORE=	makes a kernel panic on this version of FreeBSD
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WARNING:"
	@${ECHO_CMD} "This version ${PORTVERSION} of the coda client has not been tested at all under FreeBSD."
	@${ECHO_CMD} "Previous version 6.0.7 was known to cause a kernel panic."
	@${ECHO_CMD} "If you make some tests, please send the results to ports@FreeBSD.org"
	@${ECHO_CMD} ""
.endif

.include <bsd.port.post.mk>
