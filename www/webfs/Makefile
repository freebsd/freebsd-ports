# New ports collection makefile for:	webfs
# Version required:			1.0
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	webfs-1.0
CATEGORIES=	www
MASTER_SITES=	http://me.IN-Berlin.DE/~kraxel/dl/

MAINTAINER=	jedgar@FreeBSD.org

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
