# New ports collection makefile for:	coda
# Date created:		11 May 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	coda-doc
PORTVERSION=	5.2.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
DISTNAME=	coda-doc-5.2.0-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	An experimental, replicated, high-performance network file system

WRKSRC=		${WRKDIR}/usr

MAN1=		cfs.1 \
		clog.1 \
		cmon.1 \
		cpasswd.1 \
		ctokens.1 \
		cunlog.1 \
		filcon.1 \
		hoard.1 \
		mvdb.1 \
		rdsinit.1 \
		repair.1 \
		rvmutl.1 \
		spy.1
MAN3=		histo.3 \
		rds_fake_free.3 \
		rds_free.3 \
		rds_init_heap.3 \
		rds_load_heap.3 \
		rds_malloc.3 \
		rds_prealloc.3 \
		rds_statistics.3 \
		rds_zap_heap.3 \
		rvm_abort_transaction.3 \
		rvm_begin_transaction.3 \
		rvm_create_log.3 \
		rvm_create_segment.3 \
		rvm_end_transaction.3 \
		rvm_flush.3 \
		rvm_initialize.3 \
		rvm_load_segment.3 \
		rvm_map.3 \
		rvm_modify_bytes.3 \
		rvm_print_statistics.3 \
		rvm_query.3 \
		rvm_set_options.3 \
		rvm_set_range.3 \
		rvm_statistics.3 \
		rvm_terminate.3 \
		rvm_truncate.3 \
		rvm_unmap.3 \
		timing.3
MAN5=		backuplogs.5 \
		dumpfile.5 \
		dumplist.5 \
		maxgroupid.5 \
		multicastagents.5 \
		multicastgroups.5 \
		passwd.coda.5 \
		servers.5 \
		vicetab.5 \
		volumelist.5 \
		vrdb.5 \
		vrlist.5 \
		vsgdb.5 \
		vstab.5
MAN8=		au.8 \
		auth2.8 \
		backup.8 \
		bldvldb.8 \
		codasrv.8 \
		createvol.8 \
		createvol_rep.8 \
		initpw.8 \
		merge.8 \
		norton.8  \
		pdbtool.8 \
		purgevol.8 \
		purgevol_rep.8 \
		readdump.8 \
		replay.8 \
		startserver.8 \
		updateclnt.8 \
		updatesrv.8 \
		venus.8 \
		volutil.8 \
		vutil.8

do-build:
	@${ECHO} "At present, Coda documentation is distributed in html, man, ps, and ppt forms"
	@${ECHO} "but documentation source is not available.  It should appear in a release"
	@${ECHO} "or two."

do-install:
	${FIND} ${WRKSRC} -type d -exec chmod 755 {} \;
	cd ${WRKSRC}; tar cf - man | (cd ${PREFIX}; tar xvf -)
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)
.endif

.include <bsd.port.mk>
