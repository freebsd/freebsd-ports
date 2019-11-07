# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	wmfishtime
PORTVERSION=	1.24
PORTREVISION=	7
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		http://www.sourcefiles.org/Toys/Clocks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time/date applet for WindowMaker with fishes swimming around

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20
USE_XORG=	x11

MAKE_ARGS=	CFLAGS="${CPPFLAGS} ${CFLAGS} -Wall" \
		LDFLAGS="${LDFLAGS}"
PLIST_FILES=	bin/wmfishtime man/man1/wmfishtime.1.gz

CPPFLAGS+=		$$(pkg-config --cflags gdk-x11-2.0 x11)
LDFLAGS+=		$$(pkg-config --libs gdk-x11-2.0 x11) -lm

post-patch:
	${REINPLACE_CMD} -E -e 's|1\.23|${PORTVERSION}|g' ${WRKSRC}/fishmon.c ${WRKSRC}/wmfishtime.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmfishtime.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
