# New ports collection makefile for:	timelimit
# Date created:				9 June 2001
# Whom:					roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	timelimit
PORTVERSION=	1.0.b3
CATEGORIES=	sysutils
MASTER_SITES=	http://ringwraith.online.bg/~roam/devel/sys/timelimit/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org

MAN8=		timelimit.8

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/timelimit ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/timelimit.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
