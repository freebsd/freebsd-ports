# New ports collection makefile for:	webfs
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	webfs
PORTVERSION=	1.6
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.strusel007.de/linux/misc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
MAN1=		webfsd.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 400000
BROKEN=		"Requires FreeBSD 4.x or greater due to ipv6 support"
.endif

do-configure:
	@${CP} ${WRKSRC}/webfsd.man ${WRKSRC}/webfsd.1
.for file in webfsd.1 main.c Makefile
	@${PERL} -pi.orig -e 's|/etc/mime.types|${PREFIX}/etc/webfsd/mime.types|' ${WRKSRC}/${file}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.1 ${PREFIX}/man/man1
.if !exists(${PREFIX}/etc/webfsd/mime.types)
	@${MKDIR} ${PREFIX}/etc/webfsd
	@${ECHO} "# Insert mime types here" > ${PREFIX}/etc/webfsd/mime.types
.endif

.include <bsd.port.post.mk>
