# New ports collection makefile for:	popcheck
# Date created:		25 Jan 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	popcheck
PORTVERSION=	1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.ludd.luth.se/~staham/linux/programs/
DISTNAME=	popcheck

MAINTAINER=	hsn@netmag.cz
COMMENT=	Preview and delete messages in POP3 mailbox

ALL_TARGET=	popcheck

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		popcheck.1
.endif

PLIST_FILES=	bin/popcheck

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/popcheck ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
		${INSTALL_MAN} ${WRKSRC}/popcheck.1 ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>
