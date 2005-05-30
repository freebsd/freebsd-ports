# New ports collection makefile for:	cursor-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cursor-bluecurve-theme

COMMENT=	The Bluecurve X cursor themes

# we only need gdk-pixbuf for building cursorthemegen, so do not USE_GNOME
BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gdk-pixbuf-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20

MASTERDIR=	${.CURDIR}/../bluecurve-themes

THEMES=		Bluecurve Bluecurve-inverse

.for t in ${THEMES}
BC_HIERS+=	${WRKSRC}/art/cursor/${t}/${t}:${PREFIX}/lib/X11/icons/${t}/cursors
PLIST_DIRS+=	lib/X11/icons/${t}/cursors lib/X11/icons/${t}
.endfor

do-build:
	cd ${WRKSRC}/art/cursor/cursorthemegen \
		&& ${CC} ${CFLAGS} `pkg-config --cflags --libs gdk-pixbuf-2.0` \
			-o ${WRKSRC}/cursorthemegen main.c themefile.c
.for t in ${THEMES}
	cd ${WRKSRC}/art/cursor/${t} \
		&& ${WRKSRC}/cursorthemegen ${t}.cursortheme ${t}
.endfor

.include "${MASTERDIR}/bsd.bluecurve.mk"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
BUILD_DEPENDS+=	xcursorgen:${X_CLIENTS_PORT}	# needed by cursorthemegen
RUN_DEPENDS+=	xcursorgen:${X_CLIENTS_PORT}	# for the lib/X11/icons directory
.else
IGNORE=		your X Window System is too old; install x11/xorg or x11/XFree86-4 and try again
.endif

.include <bsd.port.post.mk>
