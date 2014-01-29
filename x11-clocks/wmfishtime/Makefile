# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	wmfishtime
PORTVERSION=	1.24
PORTREVISION=	4
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A time/date applet for WindowMaker with fishes swimming around

USE_GNOME=	gtk12

GTK_LIBS?=	`${GTK_CONFIG} --libs`
GTK_CFLAGS?=	`${GTK_CONFIG} --cflags`
MAKE_ARGS+=	CFLAGS="${CPPFLAGS} ${CFLAGS} -Wall ${GTK_CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		GTK_LIBS="${GTK_LIBS}"
PLIST_FILES=	bin/wmfishtime man/man1/${PORTNAME}.1.gz

post-patch:
	${REINPLACE_CMD} -E -e "s@1\.23@1\.24@g" ${WRKSRC}/fishmon.c ${WRKSRC}/wmfishtime.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmfishtime.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
