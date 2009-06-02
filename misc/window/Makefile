# New ports collection makefile for:	window
# Date created:				31 May 2009
# Whom:					Tom Rhodes <trhodes@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	window
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://people.FreeBSD.org/~trhodes/

MAINTAINER=	trhodes@FreeBSD.org
COMMENT=	The FreeBSD usr.bin/window application

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800093
IGNORE=		window-1.0 is still part of the base system
.endif

WRKSRC=		${WRKDIR}/window

MAN1=		window.1
PLIST_FILES=	bin/window

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/window ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.post.mk>
