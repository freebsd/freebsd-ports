# New ports collection makefile for:	spamd
# Date created:		23 June 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	spamd
PORTVERSION=	3.4
CATEGORIES=	mail
MASTER_SITES=	http://pf4freebsd.love2party.net/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	max@love2party.net
COMMENT=	Traps spammers with a very slow smtp-login and return 4xx error

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

MAN5=		spamd.conf.5
MAN8=		spamd.8 spamd-setup.8

MANCOMPRESSED=	maybe

MAKE_ARGS=	MANDIR="${PREFIX}/man/man"

SAMPLE_SPAMD_CONF=	${PREFIX}/etc/spamd.conf.sample
SAMPLE_SPAMD_RC=	${PREFIX}/etc/rc.d/spamd.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		"Only for 5.0 and above"
.endif

.if ${OSVERSION} < 502106
RUN_DEPENDS=	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf
.endif

post-patch:
	${SED} -e 's!%%LOCALBASE%%!${LOCALBASE}!'	\
		${PATCHDIR}/local-patch.sed | ${PATCH} 	\
		${WRKSRC}/spamd-setup/spamd-setup.c

pre-su-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
	@if [ ! -f ${SAMPLE_SPAMD_RC} ]; then			\
		${ECHO_MSG} "Installing ${SAMPLE_SPAMD_RC} startup file."; \
		${INSTALL_SCRIPT} ${FILESDIR}/spamd.sh.sample	\
		${SAMPLE_SPAMD_RC};				\
	fi
	@if [ ! -f ${SAMPLE_SPAMD_CONF} ]; then			\
		${ECHO_MSG} "Installing ${SAMPLE_SPAMD_CONF} file."; \
		${INSTALL_DATA} ${WRKSRC}/spamd/spamd.conf	\
		${SAMPLE_SPAMD_CONF};				\
	fi

.include <bsd.port.post.mk>
