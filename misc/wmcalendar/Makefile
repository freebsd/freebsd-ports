# New ports collection makefile for:	wmcalendar
# Date created:				24 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmcalendar
PORTVERSION=	0.3.6
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	A dockable calendar with interface to iCalendar based calendars

LIB_DEPENDS=	ical.0:${PORTSDIR}/devel/libical

BUILD_WRKSRC=	${WRKSRC}/Src

USE_GNOME=	gtk12
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		wmCalendar.1

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/wmCalendar ${PREFIX}/bin
	@${INSTALL_MAN} ${BUILD_WRKSRC}/wmCalendar.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
