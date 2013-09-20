# Created by: Arjan van der Velde <noresult@xs4all.nl>
# $FreeBSD$

PORTNAME=	spindown
PORTVERSION=	0.3a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.noresult.net/freebsd/spindown/

MAINTAINER=	noresult@noresult.net
COMMENT=	SCSI/firewire harddrive spindown daemon

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=	spindown.1
PLIST_FILES=	sbin/spindown etc/rc.d/spindown

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spindown ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/spindown ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/spindown.1 ${MANPREFIX}/man/man1/spindown.1

.include <bsd.port.mk>
