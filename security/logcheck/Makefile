# Ports collection makefile for:	logcheck
# Date created:		9 December 1999
# Whom:			Dan Langille <dan@freebsddiary.org>
#
# $FreeBSD$
#

PORTNAME=	logcheck
PORTVERSION=	1.2.54
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Auditing tool for system logs on Unix boxes

BUILD_DEPENDS=	docbook2man:${PORTSDIR}/textproc/docbook2X
RUN_DEPENDS=	lockfile:${PORTSDIR}/mail/procmail \
		bash:${PORTSDIR}/shells/bash

LOGCHECK_USER=	logcheck
LOGCHECK_UID=	915
LOGCHECK_GROUP=	${LOGCHECK_USER}
LOGCHECK_GID=	${LOGCHECK_UID}

# Enable Perl dependency for logtail script
USE_PERL5=	5.8.0+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BINMODE=	755
SHAREMODE=	640
SUB_LIST+=	LOGCHECK_USER=${LOGCHECK_USER} \
		LOGCHECK_UID=${LOGCHECK_UID} \
		LOGCHECK_GROUP=${LOGCHECK_GROUP} \
		LOGCHECK_GID=${LOGCHECK_GID}
SUB_FILES=	pkg-install pkg-deinstall pkg-message
CONFIG_DIRS=	cracking.d ignore.d.paranoid ignore.d.server \
		ignore.d.workstation violations.d violations.ignore.d
DOCS=		AUTHORS CHANGES CREDITS LICENSE TODO docs/README*
PORTDOCS=	${DOCS:T}
MAN8=		logcheck.8 logtail.8

do-build:
	@${REINPLACE_CMD} -e 's!/var/log/syslog!/var/log/messages!' \
		${WRKSRC}/etc/logcheck.logfiles
	@${REINPLACE_CMD} -e 's!/etc/logcheck!${ETCDIR}!' \
		-e 's!/usr/share/doc/logcheck-database/README.logcheck-database.gz!${DOCSDIR}/README.logcheck-database!' \
		${WRKSRC}/docs/logcheck.sgml
	@cd ${WRKSRC}/docs && docbook2man -s \
		/usr/local/share/docbook2X/xslt/man/docbook.xsl \
		--sgml logcheck.sgml 2> /dev/null \
		&& ${MV} Logcheck.8 logcheck.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/logcheck ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/src/logtail ${PREFIX}/sbin
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${INSTALL} -d /var/db/logcheck
	@${INSTALL} -d /var/run/logcheck
	${CHOWN} ${LOGCHECK_USER}:${LOGCHECK_GROUP} /var/db/logcheck
	@${ECHO_CMD} '@exec ${CHOWN} -R ${LOGCHECK_USER}:${LOGCHECK_GROUP} \
		/var/db/logcheck' >> ${TMPPLIST}
	${CHOWN} ${LOGCHECK_USER}:${LOGCHECK_GROUP} /var/run/logcheck
	@${ECHO_CMD} '@exec ${CHOWN} -R ${LOGCHECK_USER}:${LOGCHECK_GROUP} \
		/var/run/logcheck' >> ${TMPPLIST}
	@${INSTALL} -d ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/etc/logcheck.conf \
		${ETCDIR}/logcheck.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/etc/logcheck.logfiles \
		${ETCDIR}/logcheck.logfiles.sample
.for i in ${CONFIG_DIRS}
	@${INSTALL} -d ${ETCDIR}/${i}
	@${INSTALL_DATA} ${WRKSRC}/rulefiles/linux/${i}/* ${ETCDIR}/${i}
.endfor
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/debian/logcheck.cron.d \
		${EXAMPLESDIR}/crontab.in
.endif
	${CHOWN} -R root:${LOGCHECK_GROUP} ${ETCDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R root:${LOGCHECK_GROUP} \
		${ETCDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_MAN} ${WRKSRC}/docs/*.8 ${MAN8PREFIX}/man/man8

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	${CHMOD} 644 ${DOCSDIR}/*
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
