# New ports collection makefile for:	spamd
# Date created:		23 June 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	spamd
PORTVERSION=	3.5
CATEGORIES=	mail
MASTER_SITES=	http://pf4freebsd.love2party.net/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	mlaier@freebsd.org
COMMENT=	Traps spammers with a very slow smtp-login and return 4xx error

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

USE_REINPLACE=	yes

MAN5=		spamd.conf.5
MAN8=		spamd.8 spamd-setup.8 spamdb.8 spamlogd.8

SAMPLE_SPAMD_CONF=	${PREFIX}/etc/spamd.conf.sample
SAMPLE_SPAMD_RC=	${PREFIX}/etc/rc.d/spamd.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Only for 5.0 and above"
.endif

.if ${OSVERSION} < 502106
RUN_DEPENDS=	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf
LOCAL_PFCTL=	${PREFIX}/sbin/pfctl
.else
LOCAL_PFCTL=	/sbin/pfctl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCAL_PFCTL%%|${LOCAL_PFCTL}|;	\
	    s|%%LOCAL_SPAMD_CONF%%|${PREFIX}/etc/spamd.conf|'		\
	    ${WRKSRC}/spamd-setup/spamd-setup.c

pre-su-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/spamd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 ${PREFIX}/man/man8
	@if [ ! -f ${SAMPLE_SPAMD_RC} ]; then			\
		${ECHO_MSG} "Installing ${SAMPLE_SPAMD_RC} startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/spamd.sh.sample	\
		${SAMPLE_SPAMD_RC};				\
	fi
	@if [ ! -f ${SAMPLE_SPAMD_CONF} ]; then			\
		${ECHO_MSG} "Installing ${SAMPLE_SPAMD_CONF} file."; \
		${INSTALL_DATA} ${WRKSRC}/doc/spamd.conf	\
		${SAMPLE_SPAMD_CONF};				\
	fi

.include <bsd.port.post.mk>
