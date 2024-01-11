PORTNAME=	spindown
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.noresult.net/freebsd/spindown/

MAINTAINER=	noresult@noresult.net
COMMENT=	SCSI/firewire harddrive spindown daemon
WWW=		https://www.noresult.net/freebsd/spindown/

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	sbin/spindown etc/rc.d/spindown share/man/man1/spindown.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spindown ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/spindown ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/spindown.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
