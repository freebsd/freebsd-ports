# New ports collection makefile for:    spamd
# Date created:         04 April 2007
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	spamd
PORTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=freebsdspamd
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ohauer@gmx.de
COMMENT=	Traps spammers with a very slow smtp-login and return 4xx error

USE_RC_SUBR?=	obspamd obspamlogd

SPAMDUSER?=	_spamd
SPAMDGROUP?=	_spamd
SPAMDDIR?=	/var/empty

SPAMDUID=	132
SPAMDGID=	${SPAMDUID}

MAN5=		spamd.conf.5
MAN8=		spamd.8 spamd-setup.8 spamdb.8 spamlogd.8
PORTDOCS=	ipfw-spamd.txt spamdb.txt

PLIST_DIRS=	etc/spamd
PLIST_FILES=	libexec/spamlogd \
		sbin/spamd-setup \
		sbin/spamdb \
		etc/spamd/spamd.conf.sample

CONFIG_DIR=		${PREFIX}/etc/spamd
SAMPLE_SPAMD_CONF=	${CONFIG_DIR}/spamd.conf.sample

PLIST_SUB=	SPAMDDIR=${SPAMDDIR} \
		SPAMDUSER=${SPAMDUSER} \
		SPAMDGROUP=${SPAMDGROUP} \
		SPAMDUID=${SPAMDUID} \
		SPAMDGID=${SPAMDGID}

# If you are a CPANEL user the this option is for you!
# CPANEL sends periodic a 'kill -TERM spamd' to the SpamAssassin spamd, and
# this kills also the OpenBSD spamd daemon.
# With this option spamd will be installed as obspamd, and the rc script will
# be adjusted. Man page and pid file will not be renamed!
.if !defined(CPANEL)
PLIST_FILES+=	libexec/spamd
PLIST_SUB+=	SPAMDBIN=spamd
.else
PLIST_FILES+=	libexec/obspamd
PLIST_SUB+=	SPAMDBIN=obspamd
.endif

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

pre-fetch:
	@${ECHO} ""
	@${ECHO} " **** UPGRADE WARNING:  SYNC PROTOCOL CHANGED ****"
	@${ECHO} " If you have spamd in distributed environment stop"
	@${ECHO} " sync between old (4.1.x) and new version"
	@${ECHO} " until every node is updated"
	@${ECHO} ""
	@read -p "Hit ^c now to stop, any key to continue: " -t 5 a || true
	@${ECHO} ""

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

do-install:
.if !defined(CPANEL)
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
.else
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec/obspamd
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/etc/spamd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 ${PREFIX}/man/man8
	@if [ ! -d ${CONFIG_DIR} ]; then                        \
		${MKDIR} ${CONFIG_DIR}; \
	fi
	@if [ ! -f ${SAMPLE_SPAMD_CONF} ]; then                 \
		${ECHO_MSG} "Installing ${SAMPLE_SPAMD_CONF} file."; \
		${ECHO_MSG} "${INSTALL_DATA} -v -p ${WRKSRC}/etc/spamd.conf ${SAMPLE_SPAMD_CONF}";                              \
		${INSTALL_DATA} -v -p ${WRKSRC}/etc/spamd.conf  \
		${SAMPLE_SPAMD_CONF};                           \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipfw-spamd.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/spamdb.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
