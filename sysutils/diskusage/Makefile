# New ports collection makefile for:	diskusage
# Whom:			maske
# Date created:		23 August 1999
#
# $FreeBSD$
#

PORTNAME=	diskusage
PORTVERSION=	1.05
CATEGORIES=	sysutils
MASTER_SITES=	http://www.maske.org/apps/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows current user diskusage and sum in human-readable format

MAN1=		diskusage.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/diskusage
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/diskusage

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/diskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/diskusage.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
