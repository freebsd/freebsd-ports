# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cursor-bluecurve-theme

COMMENT=	The Bluecurve X cursor themes

# we only need gdk-pixbuf for building cursorthemegen, so do not USE_GNOME
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gdk-pixbuf-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20

MASTERDIR=	${.CURDIR}/../bluecurve-themes

THEMES=		Bluecurve Bluecurve-inverse LBluecurve LBluecurve-inverse

.for t in ${THEMES}
BC_HIERS+=	${WRKSRC}/art/cursor/${t}/${t}:${PREFIX}/lib/X11/icons/${t}/cursors
.endfor

NO_STAGE=	yes
post-patch:
.for t in ${THEMES}
	@${REINPLACE_CMD} -e 's|dnd_|dnd-|' \
		${WRKSRC}/art/cursor/${t}/${t}.cursortheme
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

BUILD_DEPENDS+=	xcursorgen:${PORTSDIR}/x11/xcursorgen	# needed by cursorthemegen
RUN_DEPENDS+=	xcursorgen:${PORTSDIR}/x11/xcursorgen	# for the lib/X11/icons directory

.include <bsd.port.post.mk>
