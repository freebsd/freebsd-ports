# New ports collection makefile for:    detach
# Date created:		2 November 1999
# Whom:			arnej@pvv.org
#
# $FreeBSD$
#

PORTNAME=	detach
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.ntnu.no/pub/unix/utils/

MAINTAINER=	arnej@pvv.org
COMMENT=	Start a process detached from a terminal

MAN1=		detach.1
PLIST_FILES=	bin/detach

do-install:
	${INSTALL_PROGRAM} -m 0755 ${WRKSRC}/detach ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/detach.1 ${PREFIX}/man/man1/detach.1

.include <bsd.port.mk>
