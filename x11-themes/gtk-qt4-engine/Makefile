# New ports collection makefile for:    gtk-qt-engine
# Date created:                         23 February 2004
# Whom:                                 Danny Pansters <danny@ricin.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt-engine
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.freedesktop.org/~davidsansome/ \
		http://freebsd.ricin.com/ports/distfiles/

MAINTAINER=	danny@ricin.com
COMMENT=	GTK-QT Theme Engine allows GTK2 apps to use QT (KDE) themes

LIB_DEPENDS=	kdecore:${PORTSDIR}/x11/kdelibs3

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gtk20
USE_QT_VER=	3

PLIST_SUB=	GTK_VER=${GTK2_VERSION}
PLIST_SUB+=	X11BASE=${X11BASE} LOCALBASE=${LOCALBASE}

CONFIGURE_ARGS+=--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

pre-configure:
	@${REINPLACE_CMD} -e "s|/share/themes/|/X11R6/share/themes/|" \
		${WRKSRC}/kcm_gtk/kcmgtk.cpp

post-configure:
	@${REINPLACE_CMD} -e "s|/usr/lib/menu|/tmp/menu|" \
		${WRKSRC}/kcm_gtk/Makefile
	@${REINPLACE_CMD} -e \
		"s|/usr/share/applications|${LOCALBASE}/share/applications/kde|" \
		${WRKSRC}/kcm_gtk/Makefile

post-install:
	@${RM} /tmp/menu/kcmgtk.menu
	@if [ "`ls /tmp/menu`" = "" ]; then ${RMDIR} /tmp/menu; fi
	@${INSTALL_DATA} ${WRKSRC}/kcm_gtk/kcm_kcmgtk.la ${LOCALBASE}/lib/kde3/
	@${ECHO}
	@${ECHO} "Use \"GTK styles and fonts\" from the KDE control center to set or"
	@${ECHO} "change the GTK style. NOTE: this will overwrite your ~/.gtkrc-2.0."
	@${ECHO}

.include <bsd.port.mk>
