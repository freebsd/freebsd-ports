# New ports collection makefile for:	wmcalendar
# Date created:				24 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmcalendar
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	misc windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A dockable calendar with interface to iCalendar based calendars

LIB_DEPENDS=	ical.27:${PORTSDIR}/devel/libical

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USE_XPM=	yes
USE_GNOME=	gtk20
MAKE_ARGS=	CC="${CC}" \
		LFLAGS="`pkg-config --libs gtk+-2.0` -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}" \
		INCDIR="`pkg-config --cflags gtk+-2.0` -I${LOCALBASE}/include" \
		LIBDIR="" \
		LIBS="-lical -lXpm"

MAN1=		wmCalendar.1
PLIST_FILES=	bin/wmCalendar

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
			-e 's#/usr/X11R6#${X11BASE}#g' \
			${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalendar ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmCalendar.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
