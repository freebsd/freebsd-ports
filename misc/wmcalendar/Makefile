# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	wmcalendar
PORTVERSION=	0.5.2
PORTREVISION=	15
CATEGORIES=	misc windowmaker
MASTER_SITES=	SF

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Dockable calendar with interface to iCalendar based calendars

LIB_DEPENDS=	libical.so:devel/libical

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USES=		pkgconfig
USE_XORG=	xpm
USE_GNOME=	gtk20
MAKE_ARGS=	CC="${CC}" \
		LFLAGS="`pkg-config --libs gtk+-2.0` -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS}" \
		INCDIR="`pkg-config --cflags gtk+-2.0` -I${LOCALBASE}/include" \
		LIBDIR="" \
		LIBS="-lical -lX11 -lXext -lXpm -lm"

PLIST_FILES=	bin/wmCalendar man/man1/wmCalendar.1.gz

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
			-e 's#/usr/X11R6#${LOCALBASE}#g' \
			${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalendar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmCalendar.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
