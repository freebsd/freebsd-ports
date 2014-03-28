# Created by: Dan Langille <dan@freebsddiary.org>
# $FreeBSD$

PORTNAME=	logcheck
PORTVERSION=	1.3.16
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Auditing tool for system logs on Unix boxes

LICENSE=	GPLv2

RUN_DEPENDS=	mime-construct:${PORTSDIR}/mail/mime-construct \
		lockfile:${PORTSDIR}/mail/procmail \
		bash:${PORTSDIR}/shells/bash

LOGCHECK_USER=	logcheck
LOGCHECK_GROUP=	${LOGCHECK_USER}
USERS=		${LOGCHECK_USER}
GROUPS=		${LOGCHECK_GROUP}

BASEDIR?=	# None. portlint compliance
DBDIR=		${BASEDIR}/var/db/${PORTNAME}
RUNDIR=		${BASEDIR}/var/run/${PORTNAME}

OPTIONS_DEFINE=	CRON
CRON_DESC=	Install cron script automatically
.if !defined(BATCH)
OPTIONS_DEFAULT=CRON
.endif

# Enable Perl dependency for logtail script
USES=		perl5 shebangfix tar:xz

WRKSRC=		${WRKDIR}/${DISTNAME:S!_!-!}
BINMODE=	755
SHAREMODE=	640
SUB_LIST+=	LOGCHECK_USER=${LOGCHECK_USER} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		CRON=${PORT_OPTIONS:MCRON}
SUB_FILES=	pkg-install pkg-deinstall pkg-message
PLIST_SUB+=	LOGCHECK_USER=${LOGCHECK_USER} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		DBDIR=${DBDIR} RUNDIR=${RUNDIR}
SHEBANG_FILES=	src/logcheck src/logtail src/logtail2
CONFIG_DIRS=	cracking.d ignore.d.paranoid ignore.d.server \
		ignore.d.workstation violations.d violations.ignore.d
DOCS=		AUTHORS CHANGES CREDITS LICENSE TODO docs/README*
PORTDOCS=	${DOCS:T}
MAN_FILES=	logcheck.8 logtail.8 logtail2.8

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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail2 ${STAGEDIR}${PREFIX}/sbin
	@${INSTALL} -d ${STAGEDIR}${DBDIR} ${STAGEDIR}${RUNDIR}
	@${INSTALL} -d ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/etc/logcheck.conf \
		${STAGEDIR}${ETCDIR}/logcheck.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/logcheck.logfiles \
		${STAGEDIR}${ETCDIR}/logcheck.logfiles.sample
.for i in ${CONFIG_DIRS}
	@${INSTALL} -d ${STAGEDIR}${ETCDIR}/${i}
	@${INSTALL_DATA} ${WRKSRC}/rulefiles/linux/${i}/* \
		${STAGEDIR}${ETCDIR}/${i}
.endfor
	@${INSTALL} -d ${STAGEDIR}${DATADIR}/detectrotate
	@${INSTALL_DATA} ${WRKSRC}/src/detectrotate/*.dtr \
		${STAGEDIR}${DATADIR}/detectrotate
	@${INSTALL} -d ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} -m 0644 ${WRKSRC}/debian/logcheck.cron.d \
		${STAGEDIR}${EXAMPLESDIR}/crontab.in
	@${ECHO_CMD} '@exec ${CHGRP} -R ${LOGCHECK_GROUP} \
		${ETCDIR:S|^${PREFIX}/|%D/|} \
		${DATADIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
.for i in ${MAN_FILES}
	@${INSTALL_MAN} ${WRKSRC}/docs/$i ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${GZIP_CMD} ${STAGEDIR}${MAN8PREFIX}/man/man8/$i
.endfor
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} -m 0644 ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
