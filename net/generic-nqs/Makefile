# New ports collection makefile for:	nqs (Generic NQS)
# Date created:         01 May 1998
# Whom:                 tonym
#
# $FreeBSD$
#
# View this file with tabstop=4
#

PORTNAME=			Generic-NQS
PORTVERSION=		3.50.9
PORTREVISION=		2
CATEGORIES=			net
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=		tonym@biolateral.com.au
COMMENT=	Generic Network Queuing System

USE_BZIP2=		yes
IS_INTERACTIVE=	yes
NO_PACKAGE=		have to build on site due to the descriptors created in\
				/var/spool/nqs (default location) and the configuration\
				procedure

#
# NQS gets configured, built and installed via its own SETUP script
#
# can call with --config, --compile or --install (in that order)
# and provided the previous steps have been done and it then goes thru
# everything from the called argument
#
# In order to fit in with the FreeBSD ports, modified SETUP so it has
# 3 new targets --fbconfig, --fbcompile, --fbinstall
# these differ in that they only do the current stage and *not* everything
# from there on in
#

HOSTNAME=	`uname -n`
RELEASE=	`uname -r | cut -d'-' -f 1`
HARDWARE=	`uname -m`

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	SETUP
CONFIGURE_ARGS=		--fbconfig

#
# In the files directory we have:
#

DUMMYMAKE=	Makefile
STARTUP=	nqs.sh
TEMPLATE=	i386-unknown-freebsd2.2.6

#
# We rename TEMPLATE (which is known to work for 2.2.6 up to and including
#   4.0 current Mar 07) to the release number of this machine.
# Maybe this is a mistake. NQS will auto generate a file from a similar
#	Platorm description file, but you would have to run make twice
#	in this case.
#

PLATFORMDIR=${WRKSRC}/SETUPDir/Platforms
PLATFORM=	${HARDWARE}-unknown-freebsd${RELEASE}

#
# NQS configure generates a config file in
#	Build-Tree/${PLATFORM}/${HOSTNAME}/SETUP/General.h
# We can use this to extract what was actually configured such as
#	where the nqsdaemon resides. We just want the NQS_ROOTDIR
#	out of it for the post-install when we put in system startup file.
#

CONFIGFILE=	${WRKSRC}/Build-Tree/${PLATFORM}/${HOSTNAME}/SETUP/General.h
MANDIR=		${WRKSRC}/Source-Tree/man/man1/all-systems
RCDIR=		${PREFIX}/etc/rc.d
SYSINST=	${SCRIPTDIR}/create-nqs-rc.sh
SYSLOGFIX=	${SCRIPTDIR}/syslog-add.sh
PLISTFIX=	${SCRIPTDIR}/fix-PLIST.mktmp.sh
CREATEQ=	${SCRIPTDIR}/create-example-batch-queues

MAN1=		nmapmgr.1 nqs.1 nqsconfig.1 nqsgs.1 nqsrn.1\
			qacct.1 qalter.1 qcat.1 qcmplx.1 qdel.1 qdev.1\
			qhold.1 qjob.1 qlimit.1 qmgr.1m qmsg.1 qpr.1\
			qresume.1 qrls.1 qstat.1 qstatc.1 qsub.1 qsuspend.1
#
# Thus ends the definitions
#

#
# Ok get a working platform description file in there.
# We need a dummy top level Makefile as NQS will put its Makefile
# in Build-Tree/${PLATFORM}/${HOSTNAME}
# Need to have the SETUP scripts executable.
# Remove the dross *.man files qcat.man and list_nqs_queues.man
# Rename man page to fit BSD extensions
#

post-patch:
	@${MV} ${WRKSRC}/SETUPDir/GSetup-Scripts/GPort-Scripts/1020-Is-gcc.sh \
	${WRKSRC}/SETUPDir/GSetup-Scripts/GPort-Scripts/1020-Is-gcc.sh.orig ; \
	${SED} -e 's|-O6 -fno-strength-reduce|${CFLAGS}|' \
	${WRKSRC}/SETUPDir/GSetup-Scripts/GPort-Scripts/1020-Is-gcc.sh.orig \
	> ${WRKSRC}/SETUPDir/GSetup-Scripts/GPort-Scripts/1020-Is-gcc.sh

pre-configure:
	@ ${SED} -e 's|XX_CFLAGS_XX|${CFLAGS}|' ${FILESDIR}/${TEMPLATE} > ${PLATFORMDIR}/${PLATFORM}; \
	${CP}   ${FILESDIR}/${DUMMYMAKE} ${WRKSRC}; \
	${CHMOD} 555 ${WRKSRC}/Source-Tree/SETUP/all-systems/*
	${RM} -f ${MANDIR}/*.man ; \
	${MV}	${MANDIR}/nmapmgr.1m ${MANDIR}/nmapmgr.1

#
# Install system boot startup file but need to find out exactly where
#	the nqs stuff was installed as this is set in nqs' own install script
# Modify syslog.conf to handle nqs
#

post-install:
	@ ${STRIP_CMD} ${PREFIX}/sbin/loaddaemon	${PREFIX}/sbin/finish_autoinst \
			${PREFIX}/sbin/lpserver		${PREFIX}/sbin/netclient \
			${PREFIX}/sbin/netdaemon	${PREFIX}/sbin/netserver \
			${PREFIX}/sbin/nqsdaemon	${PREFIX}/sbin/nqsexejob \
			${PREFIX}/sbin/nqsmkdirs	${PREFIX}/sbin/nqsmkfile \
			${PREFIX}/sbin/nqsmktrans	${PREFIX}/sbin/nqssetargv \
			${PREFIX}/sbin/pipeclient	${PREFIX}/sbin/shlexefai; \
	${STRIP_CMD}	${PREFIX}/bin/nmapmgr		${PREFIX}/bin/qacct \
			${PREFIX}/bin/qalter		${PREFIX}/bin/qcat \
			${PREFIX}/bin/qdel			${PREFIX}/bin/qdev \
			${PREFIX}/bin/qhold			${PREFIX}/bin/qlimit \
			${PREFIX}/bin/qmgr			${PREFIX}/bin/qmsg \
			${PREFIX}/bin/qpr			${PREFIX}/bin/qrls \
			${PREFIX}/bin/qstat			${PREFIX}/bin/qsub \
			${PREFIX}/bin/qsuspend; \
	${SH} ${SYSINST} ${CONFIGFILE} ${FILESDIR}/${STARTUP} ${RCDIR}/${STARTUP}; \
	${SH} ${SYSLOGFIX}; \
	${SH} ${PLISTFIX} ${CONFIGFILE} ${WRKDIR}; \
	${ECHO} "You may want run ${SH} ${CREATEQ} to actually make some queues"; \
	${ECHO} ""

.include <bsd.port.mk>
