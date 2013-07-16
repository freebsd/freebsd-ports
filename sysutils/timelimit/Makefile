# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	timelimit
PORTVERSION=	1.8
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/timelimit/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Limit the absolute execution time of a process

LICENSE=	BSD

CONFLICTS=	netpipes-[0-9]*

MAN1=		timelimit.1
PLIST_FILES=	bin/timelimit

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/timelimit ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/timelimit.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
