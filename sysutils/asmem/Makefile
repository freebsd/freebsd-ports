# New ports collection makefile for:	asfsm
# Date created:		4 June 1999
# Whom:				jack
#
# $FreeBSD$
#

PORTNAME=	asmem
PORTVERSION=	1.10
CATEGORIES=	sysutils afterstep
MASTER_SITES=	http://www.tigr.net/afterstep/download/asmem/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An AfterStep look-n-feel memory utilization monitor

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
MAN1=		asmem.1
PLIST_FILES=	bin/asmem

do-install:
	${INSTALL_PROGRAM} -g kmem -m 2755 ${WRKSRC}/asmem ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/asmem.man ${PREFIX}/man/man1/asmem.1

.include <bsd.port.mk>
