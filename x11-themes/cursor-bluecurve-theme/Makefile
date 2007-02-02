# New ports collection makefile for:	cursor-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cursor-bluecurve-theme
PORTREVISION=	2

COMMENT=	The Bluecurve X cursor themes

# we only need gdk-pixbuf for building cursorthemegen, so do not USE_GNOME
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gdk-pixbuf-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20

MASTERDIR=	${.CURDIR}/../bluecurve-themes

PREFIX=		${X11BASE}

THEMES=		Bluecurve Bluecurve-inverse

.for t in ${THEMES}
BC_HIERS+=	${WRKSRC}/art/cursor/${t}/${t}:${PREFIX}/lib/X11/icons/${t}/cursors
PLIST_DIRS+=	lib/X11/icons/${t}/cursors lib/X11/icons/${t}
.endfor

post-patch:
.for t in ${THEMES}
	@${REINPLACE_CMD} -e 's|dnd_|dnd-|' \
		${WRKSRC}/art/cursor/${t}/${t}.cursortheme
.endfor
	@${REINPLACE_CMD} -e 's|left-ptr-watch|left_ptr_watch|' \
		${WRKSRC}/art/cursor/Bluecurve-inverse/Bluecurve-inverse.cursortheme

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

BUILD_DEPENDS+=	xcursorgen:${X_CLIENTS_PORT}	# needed by cursorthemegen
RUN_DEPENDS+=	xcursorgen:${X_CLIENTS_PORT}	# for the lib/X11/icons directory

.include <bsd.port.post.mk>
