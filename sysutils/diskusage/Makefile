# New ports collection makefile for:	diskusage
# Whom:			maske
# Date created:		23 August 1999
#
# $FreeBSD$
#

PORTNAME=	diskusage
PORTVERSION=	1.04
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.maske.org/pub/FreeBSD/distfiles/

MAINTAINER=	maske@maske.org

MAN1=		diskusage.1
MANCOMPRESSED=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/diskusage

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/diskusage ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/diskusage.1.gz ${PREFIX}/man/man1

.include <bsd.port.mk>
