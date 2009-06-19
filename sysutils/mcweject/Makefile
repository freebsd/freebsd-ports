# New ports collection Makefile for:	mcweject
# Date created:				11 Jan 2005
# Whom:					Jason Bacon <jbacon@mcw.edu>
#
# $FreeBSD$
#

PORTNAME=	mcweject
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Removable media eject

MAN1=		eject.1
SUB_FILES=	pkg-message

CONFLICTS=	eject-[0-9]*
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	sbin/eject share/examples/mcweject/eject.allow
PLIST_DIRS=	share/examples/mcweject

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
