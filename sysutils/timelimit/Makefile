# New ports collection makefile for:	timelimit
# Date created:				9 June 2001
# Whom:					roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	timelimit
PORTVERSION=	1.0.b3
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/timelimit/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	Limit the absolute execution time of a process

MAN8=		timelimit.8
PLIST_FILES=	bin/timelimit

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/timelimit ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/timelimit.8 ${PREFIX}/man/man8/

.include <bsd.port.mk>
