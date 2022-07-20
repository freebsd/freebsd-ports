PORTNAME=	gstopd
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/mr

MAINTAINER=	mr@FreeBSD.org
COMMENT=	GEOM stop daemon

PLIST_FILES=	sbin/gstopd man/man8/gstopd.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gstopd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/gstopd.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
