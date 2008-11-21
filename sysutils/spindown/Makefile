# New ports collection makefile for:  spindown
# Date created:        4 november 2008
# Whom:                Arjan van der Velde <noresult@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	spindown
PORTVERSION=	0.2a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.noresult.net/freebsd/spindown/

MAINTAINER=	noresult@noresult.net
COMMENT=	SCSI/firewire harddrive spindown daemon

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/spindown etc/rc.d/spindown

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spindown ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/spindown ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
