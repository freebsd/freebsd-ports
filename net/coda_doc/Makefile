# New ports collection makefile for:	coda
# Version required:			4.6.5
# Date created:				19 June 1998
# Whom:					Robert V. Baron <rvb@cs.cmu.edu>
#
# $Id: Makefile,v 1.2 1998/10/06 15:51:02 rvb Exp $
#

DISTNAME=	coda-doc-4.6.5-3
PKGNAME=	coda-doc-4.6.5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/coda/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rvb@cs.cmu.edu

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
		groups_coda.5 \
		maxgroupid.5 \
		multicastagents.5 \
		multicastgroups.5 \
		passwd_coda.5 \
		servers.5 \
		user_coda.5 \
		vicetab.5 \
		volumelist.5 \
		vrdb.5 \
		vrlist.5 \
		vsgdb.5 \
		vstab.5
MAN8=		au.8 \
		auth2.8 \
		authmon.8 \
		backup.8 \
		bldvldb.8 \
		createvol.8 \
		createvol_rep.8 \
		initpw.8 \
		merge.8 \
		norton.8  \
		pcfgen.8 \
		purgevol.8 \
		purgevol_rep.8 \
		pwd2pdb.8 \
		readdump.8 \
		replay.8 \
		srv.8 \
		startserver.8 \
		updateclnt.8 \
		updatemon.8 \
		updatesrv.8 \
		venus.8 \
		volutil.8 \
		vutil.8

do-build:
	@${ECHO} "At present, Coda documentation is distributed in html, man, ps, and ppt forms"
	@${ECHO} "but documentation source is not available.  It should appear in a release"
	@${ECHO} "or two."

do-install:
	cd ${WRKSRC}; tar cf - man | (cd ${PREFIX}; tar xvf -)
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; tar cf - doc | (cd ${PREFIX}/share; tar xvf -)
.endif

.include <bsd.port.mk>
