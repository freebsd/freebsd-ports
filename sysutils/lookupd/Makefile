# New ports collection makefile for:	lookupd
# Date created:				3 July 2004
# Whom:					Michael Bushkov <bushman@rsu.ru>
#
# $FreeBSD$

PORTNAME=	lookupd
PORTVERSION=	0.3.a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsu.ru/~bushman/lookupd/downloads/

MAINTAINER=	bushman@rsu.ru
COMMENT=	Lookupd daemon - IPC nsswitch implementation with system-wide caching

INSTALLS_SHLIB=	yes
USE_RC_SUBR=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
STARTUPSCRIPT=	${WRKDIR}/lookupd.sh

post-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/lookupd.sh > ${STARTUPSCRIPT}
	${INSTALL_SCRIPT} ${STARTUPSCRIPT} ${PREFIX}/etc/rc.d/lookupd.sh
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500112
IGNORE=		This version of lookupd is only supported on FreeBSD 5.1 or later
.endif

.include <bsd.port.post.mk>
