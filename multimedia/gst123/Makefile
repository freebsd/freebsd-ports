PORTNAME=	gst123
DISTVERSION=	0.4.1
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/swesterfeld/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Command-line tool to play audio and video files
WWW=		https://space.twc.de/~stefan/gst123.php

LICENSE=	LGPL20+

USES=		compiler:c++11-lang localbase gmake gnome gstreamer ncurses \
		pkgconfig tar:bzip2 xorg
USE_GNOME=	gtk30
USE_GSTREAMER=	good
USE_XORG=	x11

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS}_${OSREL:R} == FreeBSD_13
CONFIGURE_ENV=	NCURSES_CFLAGS=-I${NCURSESINC} NCURSES_LIBS=-L${NCURSESLIB}
LDFLAGS+=	${TINFO_LIB}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.post.mk>
