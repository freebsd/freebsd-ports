# New ports collection makefile for:	webfs
# Date created:				18 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	webfs
PORTVERSION=	1.16
CATEGORIES=	www ipv6
MASTER_SITES=	http://bytesex.org/misc/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_REINPLACE=	yes

MAN1=		webfsd.1
MIMEFILE?=	${PREFIX}/etc/webfsd/mime.types

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 400000
BROKEN=		"Requires FreeBSD 4.x or greater due to ipv6 support"
.endif

do-configure:
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/mime.types|${MIMEFILE}|' ${WRKSRC}/webfsd.man

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/webfsd ${PREFIX}/sbin
	@${INSTALL_MAN} ${WRKSRC}/webfsd.man ${PREFIX}/man/man1/webfsd.1
.if !exists(${PREFIX}/etc/webfsd/mime.types)
	@${MKDIR} ${PREFIX}/etc/webfsd
	@${ECHO_CMD} "# Insert mime types here" > ${PREFIX}/etc/webfsd/mime.types
.endif

.include <bsd.port.post.mk>
