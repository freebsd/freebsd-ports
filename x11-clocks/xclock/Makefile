PORTNAME=	xclock
DISTVERSION=	1.2.0
CATEGORIES=	x11-clocks

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Analog and digital clock for X
WWW=		https://gitlab.freedesktop.org/xorg/app/xclock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv tar:xz xorg xorg-cat:app
USE_XORG=	x11 xaw xft xkbfile xmu xorgproto xrender xt

PLIST_FILES=	bin/xclock \
		share/X11/app-defaults/XClock \
		share/X11/app-defaults/XClock-color \
		share/man/man1/xclock.1.gz

.include <bsd.port.mk>
