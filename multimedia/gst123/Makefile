PORTNAME=	gst123
PORTVERSION=	0.3.3
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://space.twc.de/~stefan/gst123/

MAINTAINER=	h.skuhra@gmail.com
COMMENT=	Command-line tool to play audio and video files
WWW=		https://space.twc.de/~stefan/gst123.php

LICENSE=	LGPL20

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lang localbase gmake gnome gstreamer ncurses pkgconfig \
		tar:bzip2
USE_GNOME=	gtk20
CONFIGURE_ENV=	NCURSES5_CONFIG=/usr/bin/true
LDFLAGS+=	-ltinfo -lncurses

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

USE_GSTREAMER=	good

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
