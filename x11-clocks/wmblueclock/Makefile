# New ports collection makefile for:	wmblueclock
# Date created:				25 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmblueclock
PORTVERSION=	0.0
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple dockable clock application

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/wmblueclock

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
