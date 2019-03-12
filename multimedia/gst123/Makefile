# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	gst123
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://space.twc.de/~stefan/gst123/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Command-line tool to play audio and video files

LICENSE=	LGPL20

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang gmake ncurses pkgconfig tar:bzip2
USE_GNOME=	gtk20
CONFIGURE_ENV=	NCURSES5_CONFIG=/usr/bin/true
LDFLAGS+=	-lncurses -L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	GSTREAMER1

GSTREAMER1_DESC=	Multimedia support via GStreamer 1.0 (instead of 0.10)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER1} || exists(${LOCALBASE}/libdata/pkgconfig/gstreamer-1.0.pc)
USE_GSTREAMER1=	good
.else
USE_GSTREAMER=	good
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
