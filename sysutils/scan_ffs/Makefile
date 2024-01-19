PORTNAME=	scan_ffs
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ranner.eu/stuff/

MAINTAINER=	michael@ranner.eu
COMMENT=	Scan_ffs recovers lost disklabel

USES=	tar:bzip2

PLIST_FILES=	sbin/scan_ffs share/man/man8/scan_ffs.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scan_ffs ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/scan_ffs.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
