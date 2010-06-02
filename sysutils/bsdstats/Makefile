# New ports collection makefile for:	bsdstats
# Date created:		5 August 2006
# Whom:			Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	bsdstats
PORTVERSION=	5.5
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monthly script for reporting anonymous statistics about your machine

NO_BUILD=	yes

do-install:
	${MKDIR} ${LOCALBASE}/etc/periodic/monthly
	${CP} ${FILESDIR}/300.statistics ${LOCALBASE}/etc/periodic/monthly
	${CP} ${FILESDIR}/bsdstats.sh ${LOCALBASE}/etc/rc.d
	${CHMOD} 0755 ${LOCALBASE}/etc/rc.d/bsdstats.sh
	${CHMOD} 0755 ${LOCALBASE}/etc/periodic/monthly/300.statistics
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

.include <bsd.port.mk>
