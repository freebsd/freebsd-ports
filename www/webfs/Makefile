# New ports collection makefile for:	webfs
# Version required:			0.7
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	webfs-0.7
CATEGORIES=	www
MASTER_SITES=	http://www.IN-Berlin.DE/User/kraxel/dl/

MAINTAINER=	jedgar@fxp.org

MAN1=		webfsd.1

do-configure:
	@${CP} ${WRKSRC}/webfsd.man ${WRKSRC}/webfsd.1
	@${PERL} -pi.orig -e 's|/etc/mime.types|${PREFIX}/etc/webfsd/mime.types|' ${WRKSRC}/webfsd.1
	@${PERL} -pi.orig -e 's|/etc/mime.types|${PREFIX}/etc/webfsd/mime.types|' ${WRKSRC}/main.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.1 ${PREFIX}/man/man1
.if !exists(${PREFIX}/etc/webfsd/mime.types)
	@${MKDIR} ${PREFIX}/etc/webfsd
	@${ECHO} "# Insert mime types here" > ${PREFIX}/etc/webfsd/mime.types
.endif

.include <bsd.port.mk>
