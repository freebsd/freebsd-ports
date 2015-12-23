# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	wmfishtime
PORTVERSION=	1.24
PORTREVISION=	6
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		http://www.sourcefiles.org/Toys/Clocks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time/date applet for WindowMaker with fishes swimming around

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig

MAKE_ARGS+=	CFLAGS="${CPPFLAGS} ${CFLAGS} -Wall ${GTK_CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		GTK_LIBS="${GTK_LIBS}"
PLIST_FILES=	bin/wmfishtime man/man1/wmfishtime.1.gz

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK1 GTK2
OPTIONS_DEFAULT=	GTK2

GTK1_USE=		gnome=gtk12
GTK1_CPPFLAGS=		$$(pkg-config --cflags gdk)
GTK1_LDFLAGS=		$$(pkg-config --libs gdk)
GTK2_USE=		gnome=gtk20
GTK2_CPPFLAGS=		$$(pkg-config --cflags gdk-x11-2.0 x11)
GTK2_LDFLAGS=		$$(pkg-config --libs gdk-x11-2.0 x11) -lm
TOOLKIT_DESC=		GTK Toolkit

post-patch:
	${REINPLACE_CMD} -E -e 's|1\.23|${PORTVERSION}|g' ${WRKSRC}/fishmon.c ${WRKSRC}/wmfishtime.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmfishtime.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
