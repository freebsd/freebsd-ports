# Created by: Max Laier <max@love2party.net>
# $FreeBSD$

PORTNAME=	spamd
PORTVERSION=	4.9.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=freebsdspamd.berlios

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Traps spammers with a very slow smtp-login and return 4xx error

LICENSE=	BSD

USE_RC_SUBR?=	obspamd obspamlogd

USERS=		_spamd
GROUPS=		_spamd

MAN5=		spamd.conf.5
MAN8=		spamd.8 spamd-setup.8 spamdb.8 spamlogd.8
PORTDOCS=	ipfw-spamd.txt spamdb.txt

PLIST_DIRSTRY=	%%ETCDIR%%
PLIST_FILES=	%%ETCDIR%%/spamd.conf.sample \
		libexec/spamlogd \
		sbin/spamd-setup \
		sbin/spamdb

PLIST_SUB=	SPAMDUSER=${USERS} \
		SPAMDGROUP=${GROUPS}

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
		pkg-message

SUB_LIST=	PREFIX=${PREFIX} \
		${PLIST_SUB}

.include <bsd.port.options.mk>

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
.if !defined(CPANEL)
	@${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/spamd/spamd ${PREFIX}/libexec/obspamd
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/spamlogd/spamlogd ${PREFIX}/libexec
	@${INSTALL_PROGRAM} ${WRKSRC}/spamd-setup/spamd-setup ${PREFIX}/sbin
	@${INSTALL_PROGRAM} ${WRKSRC}/spamdb/spamdb ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/etc/spamd.conf.5 ${PREFIX}/man/man5
	@${INSTALL_MAN} ${WRKSRC}/spamd/spamd.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/spamd-setup/spamd-setup.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/spamdb/spamdb.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/spamlogd/spamlogd.8 ${PREFIX}/man/man8
	@${INSTALL} -d ${ETCDIR}
	@${INSTALL_DATA} -m 644 ${WRKSRC}/etc/spamd.conf ${ETCDIR}/spamd.conf.sample

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/ipfw-spamd.txt ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/spamdb.txt ${DOCSDIR}/
.endif

post-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
