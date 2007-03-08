# New ports collection makefile for:    bluecurve-unified
# Date created:         3 October 2002
# Whom:                 Eugeney Ryzhyk
#
# $FreeBSD$
#

PORTNAME=	gtk-bluecurve-theme

COMMENT=	The Bluecurve GTK+ themes

MASTERDIR=	${.CURDIR}/../bluecurve-themes

USE_GNOME+=	gtk20
GTK2_CFLAGS=	`${LOCALBASE}/bin/pkg-config --cflags gtk+-2.0`
GTK2_LIBS=	`${LOCALBASE}/bin/pkg-config --libs gtk+-2.0`
GTK2_SOURCES=	bluecurve_rc_style.c bluecurve_style.c bluecurve_theme_main.c
GTK2_ENGINEDIR=	lib/gtk-2.0/${GTK2_VERSION}/engines

PLIST=		${WRKDIR}/pkg-plist
EXTRA_STYLES=	BerriesAndCream Gnome Grape Lime Slate Strawberry Tangerine

post-patch:
.for s in ${EXTRA_STYLES}
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' \
		${WRKSRC}/art/gtk/Bluecurve-${s}/gtk-2.0/gtkrc
.endfor

do-build:
	cd ${WRKSRC}/art/gtk/Bluecurve && \
	${CC} ${CFLAGS} -Wl,-export-dynamic -shared -fPIC \
		${GTK2_CFLAGS} ${GTK2_LIBS} -o libbluecurve.so \
			${GTK2_SOURCES}

pre-install:
	@${RM} -f ${PLIST}
	@${ECHO_CMD} "${GTK2_ENGINEDIR}/libbluecurve.so" >> ${PLIST}
	@${ECHO_CMD} "share/themes/Bluecurve/gtk-2.0/gtkrc" >> ${PLIST}
	@${ECHO_CMD} "@dirrm share/themes/Bluecurve/gtk-2.0" >> ${PLIST}
.for s in ${EXTRA_STYLES}
	@${ECHO_CMD} "share/themes/Bluecurve-${s}/gtk-2.0/gtkrc" >> ${PLIST}
	@${ECHO_CMD} "@dirrm share/themes/Bluecurve-${s}/gtk-2.0" >> ${PLIST}
.endfor
	@${ECHO_CMD} "@dirrmtry share/themes/Bluecurve" >> ${PLIST}
.for s in ${EXTRA_STYLES}
	@${ECHO_CMD} "@dirrm share/themes/Bluecurve-${s}" >> ${PLIST}
.endfor

do-install:
	${MKDIR} ${PREFIX}/${GTK2_ENGINEDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/art/gtk/Bluecurve/libbluecurve.so ${PREFIX}/${GTK2_ENGINEDIR}
	${MKDIR} ${PREFIX}/share/themes/Bluecurve/gtk-2.0
	${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve/gtk-2.0/gtkrc ${PREFIX}/share/themes/Bluecurve/gtk-2.0
.for s in ${EXTRA_STYLES}
	${MKDIR} ${PREFIX}/share/themes/Bluecurve-${s}/gtk-2.0
	${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve-${s}/gtk-2.0/gtkrc ${PREFIX}/share/themes/Bluecurve-${s}/gtk-2.0
.endfor

.include "${MASTERDIR}/Makefile"
