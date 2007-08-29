# New ports collection makefile for:	bsdstats
# Date created:		5 August 2006
# Whom:			Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	bsdstats
PORTVERSION=	5.3
PORTREVISION=	5
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	scrappy@freebsd.org
COMMENT=	Monthly script for reporting anonymous statistics about your machine

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503102 || (${OSVERSION} >= 600000 && ${OSVERSION} < 600010)
RUN_DEPENDS=	nc:${PORTSDIR}/net/netcat
.endif

NO_BUILD=	yes
PLIST_FILES=	etc/periodic/monthly/300.statistics etc/rc.d/bsdstats.sh
PLIST_DIRS=	etc/periodic/monthly \
		etc/periodic

do-install:
	${MKDIR} ${LOCALBASE}/etc/periodic/monthly
	${CP} ${FILESDIR}/300.statistics ${LOCALBASE}/etc/periodic/monthly
	${CP} ${FILESDIR}/bsdstats.sh ${LOCALBASE}/etc/rc.d
	${CHMOD} 0755 ${LOCALBASE}/etc/rc.d/bsdstats.sh
post-install:
	${CAT} ${PKGMESSAGE}
.if defined(BATCH) || defined(PACKAGE_BUILDING)
	@${ECHO_MSG} "	To activate monthly statistics reporting in /etc/periodic.conf,"
	@${ECHO_MSG} "	execute the following as root user:"
	@${ECHO_MSG}
	@${ECHO_MSG} "PKG_PREFIX=\"${PREFIX}\" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL"
	@${ECHO_MSG}
.else
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
