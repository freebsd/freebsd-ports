# New ports collection makefile for:		Ports tree snapshot utility
# Date created:					29 October 2004
# Whom:						cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	portsnap
PORTVERSION=	0.2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.daemonology.net/portsnap/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Provides secure snapshots of the ports directory

# The freebsd-sha1 port is marked IGNORE for some versions of FreeBSD,
# but for those sha1 should be found in /sbin/, so this should be safe.
RUN_DEPENDS=	bspatch:${PORTSDIR}/misc/bsdiff		\
		sha1:${PORTSDIR}/sysutils/freebsd-sha1	\
		freebsd-update-verify:${PORTSDIR}/security/freebsd-update

MAN5=		portsnap.conf.5
MAN8=		portsnap.8
PLIST_FILES=	etc/portsnap.conf.sample sbin/portsnap
PLIST_DIRS=	portsnap

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/portsnap ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/portsnap.conf.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/portsnap.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/portsnap.conf		\
		${PREFIX}/etc/portsnap.conf.sample
	${MKDIR} ${PREFIX}/portsnap

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
