# New ports collection makefile for:	bsdstats
# Date created:		5 August 2006
# Whom:			Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	bsdstats
PORTVERSION=	4.6
CATEGORIES=	sysutils
DISTFILES=

MAINTAINER=	scrappy@freebsd.org
COMMENT=	Monthly script for reporting anonymous statistics about your machine

NO_BUILD=	yes
PLIST_FILES=	etc/periodic/monthly/300.statistics
PLIST_DIRS=	etc/periodic/monthly \
		etc/periodic

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${LOCALBASE}/etc/periodic/monthly
	${CP} ${FILESDIR}/300.statistics ${LOCALBASE}/etc/periodic/monthly
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
