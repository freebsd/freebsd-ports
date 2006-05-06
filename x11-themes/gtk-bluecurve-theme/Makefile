# New ports collection makefile for:    bluecurve-unified
# Date created:         3 October 2002
# Whom:                 Eugeney Ryzhyk
#
# $FreeBSD$
#

PORTNAME=	gtk-bluecurve-theme
PORTREVISION=	1

COMMENT=	The Bluecurve GTK+ 1.x and 2.x themes

MASTERDIR=	${.CURDIR}/../bluecurve-themes

USE_REINPLACE=	yes
EXTRA_PATCHES=	${WRKDIR}/redhat-artwork-0.122-padding-fix.patch
PATCH_STRIP=	-p1

# GTK+ 1.x theme engine
USE_GNOME+=	gdkpixbuf
GTK1_CFLAGS=	`${X11BASE}/bin/gdk-pixbuf-config --cflags`
GTK1_LIBS=	`${X11BASE}/bin/gdk-pixbuf-config --libs`
GTK1_WRKSRC=	${WRKSRC}/art/gtk/Bluecurve1
GTK1_RCDIR=	gtk
GTK1_SOURCES=	bluecurve1_theme_main.c bluecurve1_theme_draw.c
GTK1_ENGINEDIR=	lib/gtk/themes/engines

# GTK+ 2.x theme engine
USE_GNOME+=	gtk20
GTK2_CFLAGS=	`${LOCALBASE}/bin/pkg-config --cflags gtk+-2.0`
GTK2_LIBS=	`${LOCALBASE}/bin/pkg-config --libs gtk+-2.0`
GTK2_WRKSRC=	${WRKSRC}/art/gtk/Bluecurve
GTK2_RCDIR=	gtk-2.0
GTK2_SOURCES=	bluecurve_rc_style.c bluecurve_style.c bluecurve_theme_main.c
GTK2_ENGINEDIR=	lib/gtk-2.0/${GTK2_VERSION}/engines

PLIST=		${WRKDIR}/pkg-plist
EXTRA_STYLES=	BerriesAndCream Gnome Grape Lime Slate Strawberry Tangerine

post-patch:
.for v in 1 2
.  for s in ${EXTRA_STYLES}
	@${REINPLACE_CMD} -e 's|/usr|${X11BASE}|' \
		${WRKSRC}/art/gtk/Bluecurve-${s}/${GTK${v}_RCDIR}/gtkrc
.  endfor
.endfor

do-build:
.for v in 1 2
	cd ${GTK${v}_WRKSRC} && \
	${CC} ${CFLAGS} -Wl,-export-dynamic -shared -fPIC \
		${GTK${v}_CFLAGS} ${GTK${v}_LIBS} -o libbluecurve.so \
			${GTK${v}_SOURCES}
.endfor

pre-install:
	@${RM} -f ${PLIST}
.for v in 1 2
	@${ECHO_CMD} "${GTK${v}_ENGINEDIR}/libbluecurve.so" >> ${PLIST}
	@${ECHO_CMD} "share/themes/Bluecurve/${GTK${v}_RCDIR}/gtkrc" >> ${PLIST}
	@${ECHO_CMD} "@dirrm share/themes/Bluecurve/${GTK${v}_RCDIR}" >> ${PLIST}
.  for s in ${EXTRA_STYLES}
	@${ECHO_CMD} "share/themes/Bluecurve-${s}/${GTK${v}_RCDIR}/gtkrc" >> ${PLIST}
	@${ECHO_CMD} "@dirrm share/themes/Bluecurve-${s}/${GTK${v}_RCDIR}" >> ${PLIST}
.  endfor
.endfor
	@${ECHO_CMD} "@dirrmtry share/themes/Bluecurve" >> ${PLIST}
.for s in ${EXTRA_STYLES}
	@${ECHO_CMD} "@dirrm share/themes/Bluecurve-${s}" >> ${PLIST}
.endfor

do-install:
.for v in 1 2
	${MKDIR} ${PREFIX}/${GTK${v}_ENGINEDIR}
	${INSTALL_PROGRAM} ${GTK${v}_WRKSRC}/libbluecurve.so ${PREFIX}/${GTK${v}_ENGINEDIR}
	${MKDIR} ${PREFIX}/share/themes/Bluecurve/${GTK${v}_RCDIR}
	${INSTALL_DATA} ${GTK${v}_WRKSRC}/${GTK${v}_RCDIR}/gtkrc ${PREFIX}/share/themes/Bluecurve/${GTK${v}_RCDIR}
.  for s in ${EXTRA_STYLES}
	${MKDIR} ${PREFIX}/share/themes/Bluecurve-${s}/${GTK${v}_RCDIR}
	${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve-${s}/${GTK${v}_RCDIR}/gtkrc ${PREFIX}/share/themes/Bluecurve-${s}/${GTK${v}_RCDIR}
.  endfor
.endfor

.include "${MASTERDIR}/Makefile"
