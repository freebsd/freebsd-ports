# Created by: Arjan van der Velde <noresult@xs4all.nl>
# $FreeBSD$

PORTNAME=	spindown
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.noresult.net/freebsd/spindown/

MAINTAINER=	noresult@noresult.net
COMMENT=	SCSI/firewire harddrive spindown daemon

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/spindown etc/rc.d/spindown man/man1/spindown.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spindown ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/spindown ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/spindown.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
