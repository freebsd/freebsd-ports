# New ports collection makefile for:	webfs
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	webfs
PORTVERSION=	1.10
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.bytesex.org/misc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
MAN1=		webfsd.1
MIMEFILE?=	${PREFIX}/etc/webfsd/mime.types

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 400000
BROKEN=		"Requires FreeBSD 4.x or greater due to ipv6 support"
.endif

do-configure:
	@${PERL} -pi.orig -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/Makefile
# author forgot to bump the revision number
	@${PERL} -pi.orig -e 's|1.9|1.10|' ${WRKSRC}/main.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.man ${PREFIX}/man/man1/webfsd.1
.if !exists(${PREFIX}/etc/webfsd/mime.types)
	@${MKDIR} ${PREFIX}/etc/webfsd
	@${ECHO} "# Insert mime types here" > ${PREFIX}/etc/webfsd/mime.types
.endif

.include <bsd.port.post.mk>
