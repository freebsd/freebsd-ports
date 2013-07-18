# Created by: Dan Langille <dan@freebsddiary.org>
# $FreeBSD$

PORTNAME=	logcheck
PORTVERSION=	1.3.15
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Auditing tool for system logs on Unix boxes

RUN_DEPENDS=	mime-construct:${PORTSDIR}/mail/mime-construct \
		lockfile:${PORTSDIR}/mail/procmail \
		bash:${PORTSDIR}/shells/bash

PORTSCOUT=	limit:^1\.2\.

LOGCHECK_USER=	logcheck
LOGCHECK_UID=	915
LOGCHECK_GROUP=	${LOGCHECK_USER}
LOGCHECK_GID=	${LOGCHECK_UID}

BASEDIR?=	# None. portlint compliance
DBDIR=		${BASEDIR}/var/db/${PORTNAME}
RUNDIR=		${BASEDIR}/var/run/${PORTNAME}

OPTIONS_DEFINE=	CRON
CRON_DESC=	Install cron script automatically
.if !defined(BATCH)
OPTIONS_DEFAULT=CRON
.endif

# Enable Perl dependency for logtail script
USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S!_!-!}
BINMODE=	755
SHAREMODE=	640
SUB_LIST+=	LOGCHECK_USER=${LOGCHECK_USER} \
		LOGCHECK_UID=${LOGCHECK_UID} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		LOGCHECK_GID=${LOGCHECK_GID} \
		PW=${PW} CRON=${PORT_OPTIONS:MCRON}
SUB_FILES=	pkg-install pkg-deinstall pkg-message
PLIST_SUB+=	DBDIR=${DBDIR} RUNDIR=${RUNDIR}
CONFIG_DIRS=	cracking.d ignore.d.paranoid ignore.d.server \
		ignore.d.workstation violations.d violations.ignore.d
DOCS=		AUTHORS CHANGES CREDITS LICENSE TODO docs/README*
PORTDOCS=	${DOCS:T}
MAN8=		logcheck.8 logtail.8 logtail2.8

PATCH_LIST=	extra-patch-debian__logcheck.cron.d \
		extra-patch-docs__logcheck.8 \
		extra-patch-etc__logcheck.conf \
		extra-patch-src__logcheck \
		extra-patch-src__logtail2
EXTRA_PATCHES=	${PATCH_LIST:C|^|${WRKDIR}/|g}

.include <bsd.port.pre.mk>

pre-patch:
.for patch in ${PATCH_LIST}
	@${SED} ${_SUB_LIST_TEMP} ${FILESDIR}/${patch}.in > ${WRKDIR}/${patch}
.endfor

post-patch:
	@${FIND} ${WRKSRC}/rulefiles -type f -name \*.orig -delete

do-build:
	@${REINPLACE_CMD} -e 's!/var/log/syslog!/var/log/messages!' \
		${WRKSRC}/etc/logcheck.logfiles
	@${REINPLACE_CMD} -e "s|#!/usr/bin/perl|#!${PERL}|" \
		${WRKSRC}/src/logtail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail2 ${PREFIX}/sbin
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${INSTALL} -d -o ${LOGCHECK_USER} -g ${LOGCHECK_GROUP} \
		${DBDIR} ${RUNDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${LOGCHECK_USER}:${LOGCHECK_GROUP} \
		${DBDIR} ${RUNDIR}' >> ${TMPPLIST}
	@${INSTALL} -d -g ${LOGCHECK_GROUP} ${ETCDIR}
	@${INSTALL_DATA} -g ${LOGCHECK_GROUP} ${WRKSRC}/etc/logcheck.conf \
		${ETCDIR}/logcheck.conf.sample
	@${INSTALL_DATA} -g ${LOGCHECK_GROUP} ${WRKSRC}/etc/logcheck.logfiles \
		${ETCDIR}/logcheck.logfiles.sample
.for i in ${CONFIG_DIRS}
	@${INSTALL} -d -g ${LOGCHECK_GROUP} ${ETCDIR}/${i}
	@${INSTALL_DATA} -g ${LOGCHECK_GROUP} ${WRKSRC}/rulefiles/linux/${i}/* \
		${ETCDIR}/${i}
.endfor
	@${INSTALL} -d -g ${LOGCHECK_GROUP} ${DATADIR}/detectrotate
	@${INSTALL_DATA} -g ${LOGCHECK_GROUP} ${WRKSRC}/src/detectrotate/*.dtr \
		${DATADIR}/detectrotate
.if ${PORT_OPTIONS:MEXAMPLES}
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} -m 0644 ${WRKSRC}/debian/logcheck.cron.d \
		${EXAMPLESDIR}/crontab.in
.endif
	@${ECHO_CMD} '@exec ${CHGRP} -R ${LOGCHECK_GROUP} \
		${ETCDIR:S|^${PREFIX}/|%D/|} \
		${DATADIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_MAN} ${WRKSRC}/docs/*.8 ${MAN8PREFIX}/man/man8

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} -m 0644 ${DOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
