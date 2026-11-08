PORTNAME=	gst123
DISTVERSION=	0.5.0
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/swesterfeld/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Command-line tool to play audio and video files
WWW=		https://space.twc.de/~stefan/gst123.php

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang localbase gmake gnome gstreamer ncurses \
		pkgconfig tar:bzip2 xorg
USE_GNOME=	gtk30
USE_GSTREAMER=	good libav
USE_XORG=	x11 xorgproto

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
