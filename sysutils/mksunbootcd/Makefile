# New ports collection makefile for:	mksunbootcd
# Date Created:				5 Jan 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	mksunbootcd
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/mksunbootcd/

MAINTAINER=	ports@oven.org
COMMENT=	Makes ISO images suitable to boot on sparc systems

MAN1=		mksunbootcd.1
PLIST_FILES=	bin/mksunbootcd

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
