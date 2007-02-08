# New ports collection makefile for:    gtk-qt-engine
# Date created:                         23 February 2004
# Whom:                                 Danny Pansters <danny@ricin.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt-engine
PORTVERSION=	0.7
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://gtk-qt.ecs.soton.ac.uk/files/${PORTVERSION}/ \
		http://freebsd.ricin.com/ports/distfiles/

MAINTAINER=	danny@ricin.com
COMMENT=	GTK-QT Theme Engine allows GTK2 apps to use QT (KDE) themes

LIB_DEPENDS=	kdecore:${PORTSDIR}/x11/kdelibs3

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gtk20
USE_QT_VER=	3

WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_ARGS+=--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

OPTIONS=	LIBBONOBOUI "Install libbonoboui if missing" off

.include <bsd.port.pre.mk>

# Note: had to turn off libbonoboui (dependency) OPTION for technical reasons
# So a "vanilla" package will have no libbonoboui support
.if defined(WITH_LIBBONOBOUI)
USE_GNOME+=	libbonoboui
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|GTK_LIBPREFIX)/gtk|PREFIX)/lib/gtk|" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|GTK_PREFIX)/share|PREFIX)/share|g" \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/lib/menu|${WRKDIR}/menu|g" \
		${WRKSRC}/kcm_gtk/Makefile.in
	@${REINPLACE_CMD} -e \
		"s|/usr/share/applications|${PREFIX}/share/applications/kde|g" \
		${WRKSRC}/kcm_gtk/Makefile.in

post-install:
	@${RM} -r ${WRKDIR}/menu
	@${RM} ${PREFIX}/share/applnk/Settings/LookNFeel/kcmgtk.desktop

.include <bsd.port.post.mk>
