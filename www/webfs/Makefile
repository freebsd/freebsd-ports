# New ports collection makefile for:	webfs
# Version required:			0.6
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	webfs-0.6
CATEGORIES=	www
MASTER_SITES=	http://www.IN-Berlin.DE/User/kraxel/dl/

MAINTAINER=	jedgar@fxp.org

MAN1=		webfsd.1

do-configure:
	@${SED} -e 's|/etc/mime.types|${PREFIX}/etc/webfsd/mime.types|' \
	    < ${WRKSRC}/webfsd.man > ${WRKSRC}/webfsd.1
	@${MV} ${WRKSRC}/main.c ${WRKSRC}/main.c.orig
	@${SED} -e 's|/etc/mime.types|${PREFIX}/etc/webfsd/mime.types|' \
	    < ${WRKSRC}/main.c.orig > ${WRKSRC}/main.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/etc/webfsd
	@${ECHO} "# Insert mime types here" > ${PREFIX}/etc/webfsd/mime.types

.include <bsd.port.mk>
