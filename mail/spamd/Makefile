# New ports collection makefile for:    spamd
# Date created:         04 April 2007
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	spamd
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	BERLIOS
MASTER_SITE_SUBDIR=freebsdspamd
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Traps spammers with a very slow smtp-login and return 4xx error

.include <bsd.port.pre.mk>

LOCAL_PFCTL=	/sbin/pfctl

USE_RC_SUBR?=	obspamd obspamlogd

SPAMDUSER?=	_spamd
SPAMDGROUP?=	_spamd
SPAMDDIR?=	/var/empty

SPAMDUID=	132
SPAMDGID=	${SPAMDUID}

MAN5=		spamd.conf.5
MAN8=		spamd.8 spamd-setup.8 spamdb.8 spamlogd.8
PORTDOCS=	ipfw-spamd.txt

PLIST_DIRS=	etc/spamd
PLIST_FILES=	libexec/spamd libexec/spamlogd \
		sbin/spamd-setup sbin/spamdb \
		etc/spamd/spamd.conf.sample

CONFIG_DIR=		${PREFIX}/etc/spamd
SAMPLE_SPAMD_CONF=	${CONFIG_DIR}/spamd.conf.sample

PLIST_SUB=	SPAMDDIR=${SPAMDDIR} \
		SPAMDUSER=${SPAMDUSER} \
		SPAMDGROUP=${SPAMDGROUP} \
		SPAMDUID=${SPAMDUID} \
		SPAMDGID=${SPAMDGID}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		pkg-message

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
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
.endif

.include <bsd.port.post.mk>
