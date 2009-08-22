# New ports collection makefile for:	tmsnc
# Date created:				4 Apr 2007
# Whom:					Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	tmsnc
PORTVERSION=	0.3.2
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/Source%20code%20and%20binaries/${PORTVERSION}

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	A textbased (console) MSN client

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tmsnc

MAN1=		tmsnc.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 602107 || (${OSVERSION} > 700000 && ${OSVERSION} < 700033)
# this port needs ncurses 5.4+
BUILD_DEPENDS+=	${LOCALBASE}/include/ncurses/ncurses.h:${PORTSDIR}/devel/ncurses
RUN_DEPENDS+=	${LOCALBASE}/include/ncurses/ncurses.h:${PORTSDIR}/devel/ncurses
.endif

.include <bsd.port.post.mk>
