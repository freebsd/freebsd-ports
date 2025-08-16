PORTNAME=	logcheck
DISTVERSION=	1.4.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Auditing tool for system logs on Unix boxes
WWW=		https://salsa.debian.org/debian/logcheck

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	docbook-to-man>0:textproc/docbook-to-man
RUN_DEPENDS=	bash:shells/bash \
		lockfile-create:sysutils/lockfile-progs \
		mime-construct:mail/mime-construct


# Enable Perl dependency for logtail script
USES=		perl5 shebangfix tar:xz
SHEBANG_FILES=	src/detectrotate/*.dtr src/logcheck src/logtail src/logtail2
BINMODE=	755
SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST+=	CRON=${PORT_OPTIONS:MCRON} \
		DBDIR=${DBDIR} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		LOGCHECK_USER=${LOGCHECK_USER}
WRKSRC=		${WRKDIR}/${PORTNAME}
USERS=		${LOGCHECK_USER}
GROUPS=		${LOGCHECK_GROUP}
PLIST_SUB+=	CHGRP=${CHGRP} \
		CHMOD=${CHMOD} \
		DBDIR=${DBDIR} \
		FIND=${FIND} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		LOGCHECK_USER=${LOGCHECK_USER} \
		RUNDIR=${RUNDIR}
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=		CRON DOCS EXAMPLES
OPTIONS_DEFAULT=	CRON
CRON_DESC=		Install cron script automatically

# None. portlint compliance
BASEDIR?=
CONFIG_DIRS=		cracking.d ignore.d.paranoid ignore.d.server \
			ignore.d.workstation violations.d violations.ignore.d
DBDIR=			${BASEDIR}/var/db/${PORTNAME}
DOCS=			AUTHORS CHANGES CREDITS TODO docs/README*
LOGCHECK_GROUP=		${LOGCHECK_USER}
LOGCHECK_USER=		logcheck
MAN1_FILES=		logcheck-test.1
MAN8_FILES=		logcheck.8 logtail.8 logtail2.8
REINPLACE_FILES=	debian/logcheck.cron.d docs/logcheck.sgml \
			docs/logtail2.8 docs/README.logcheck \
			docs/README.logcheck-database docs/README.logtail \
			etc/logcheck.conf etc/logcheck.logfiles src/logcheck \
			src/logtail2
RUNDIR=			${BASEDIR}/var/run/${PORTNAME}

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
		  ${STAGEDIR}${ETCDIR} \
		  ${STAGEDIR}${ETCDIR}/logcheck.logfiles.d \
		  ${STAGEDIR}${RUNDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck-test ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/etc/logcheck.conf \
		${STAGEDIR}${ETCDIR}/logcheck.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/logcheck.logfiles \
		${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/etc/logcheck.logfiles.d/syslog.logfiles \
		${STAGEDIR}${ETCDIR}/logcheck.logfiles.d/syslog.logfiles.sample
.for i in ${CONFIG_DIRS}
	@${MKDIR} ${STAGEDIR}${ETCDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/rulefiles/linux/${i}/* \
		${STAGEDIR}${ETCDIR}/${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/src/detectrotate/*.dtr \
		${STAGEDIR}${DATADIR}/detectrotate
.for i in ${MAN1_FILES}
	${INSTALL_MAN} ${WRKSRC}/docs/$i ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
.for i in ${MAN8_FILES}
	${INSTALL_MAN} ${WRKSRC}/docs/$i ${STAGEDIR}${PREFIX}/share/man/man8
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/logcheck.cron.d \
		${STAGEDIR}${EXAMPLESDIR}/crontab.in

.include <bsd.port.post.mk>
