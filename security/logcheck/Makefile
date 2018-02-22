# Created by: Dan Langille <dan@freebsddiary.org>
# $FreeBSD$

PORTNAME=	logcheck
PORTVERSION=	1.3.18
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	yasu@utahime.org
COMMENT=	Auditing tool for system logs on Unix boxes

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	docbook-to-man>0:textproc/docbook-to-man
RUN_DEPENDS=	mime-construct:mail/mime-construct \
		lockfile-create:sysutils/lockfile-progs \
		bash:shells/bash

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
SUB_LIST+=	LOGCHECK_USER=${LOGCHECK_USER} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		DBDIR=${DBDIR} CRON=${PORT_OPTIONS:MCRON}
SUB_FILES=	pkg-install pkg-deinstall pkg-message
PLIST_SUB+=	LOGCHECK_USER=${LOGCHECK_USER} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		DBDIR=${DBDIR} RUNDIR=${RUNDIR}
SHEBANG_FILES=	src/logcheck src/logtail src/logtail2 src/detectrotate/*.dtr
CONFIG_DIRS=	cracking.d ignore.d.paranoid ignore.d.server \
		ignore.d.workstation violations.d violations.ignore.d
DOCS=		AUTHORS CHANGES CREDITS TODO docs/README*
PORTDOCS=	${DOCS:T}
MAN1_FILES=	logcheck-test.1
MAN8_FILES=	logcheck.8 logtail.8 logtail2.8
REINPLACE_FILES=	debian/logcheck.cron.d docs/logcheck.sgml \
			docs/logtail2.8 docs/README.logcheck \
			docs/README.logcheck-database docs/README.logtail \
			etc/logcheck.conf src/logcheck src/logtail2

.include <bsd.port.pre.mk>

do-build:
.for file in ${REINPLACE_FILES}
	${REINPLACE_CMD} ${_SUB_LIST_TEMP} ${WRKSRC}/${file}
.endfor
	docbook-to-man ${WRKSRC}/docs/logcheck.sgml > ${WRKSRC}/docs/logcheck.8
	${FIND} ${WRKSRC} -type f \( -name \*.orig -o -name \*.bak \) -delete

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/detectrotate \
		  ${STAGEDIR}${DBDIR} \
		  ${STAGEDIR}${DOCSDIR} \
		  ${STAGEDIR}${ETCDIR} \
		  ${STAGEDIR}${EXAMPLESDIR} \
		  ${STAGEDIR}${RUNDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck-test ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/etc/logcheck.conf \
		${STAGEDIR}${ETCDIR}/logcheck.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/logcheck.logfiles \
		${STAGEDIR}${ETCDIR}/logcheck.logfiles.sample
.for i in ${CONFIG_DIRS}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/rulefiles/linux/${i}/* \
		${STAGEDIR}${ETCDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/detectrotate/*.dtr \
		${STAGEDIR}${DATADIR}/detectrotate
	${INSTALL_DATA} ${WRKSRC}/debian/logcheck.cron.d \
		${STAGEDIR}${EXAMPLESDIR}/crontab.in
	@${ECHO_CMD} '@exec ${CHGRP} -R ${LOGCHECK_GROUP} \
		${ETCDIR:S|^${PREFIX}/|%D/|} \
		${DATADIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
.for i in ${MAN1_FILES}
	${INSTALL_MAN} ${WRKSRC}/docs/$i ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
.for i in ${MAN8_FILES}
	${INSTALL_MAN} ${WRKSRC}/docs/$i ${STAGEDIR}${MAN8PREFIX}/man/man8
.endfor
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
