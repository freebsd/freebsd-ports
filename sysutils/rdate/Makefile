# Created by: cracauer@cons.org "Martin Cracauer"
# $FreeBSD$

PORTNAME=	rdate
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cons.org/freebsd-distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sets the clock of the local host to the time of another host

PLIST_FILES=	man/man8/${PORTNAME}.8.gz sbin/rdate

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdate ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/rdate.8 ${STAGEDIR}${PREFIX}/man/man8/

.include <bsd.port.mk>
