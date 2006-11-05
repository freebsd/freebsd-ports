# New ports collection makefile for:    gtk-qt-engine
# Date created:                         23 February 2004
# Whom:                                 Danny Pansters <danny@ricin.com>
#
# $FreeBSD$
#

PORTNAME=	gtk-qt-engine
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	http://people.freedesktop.org/~davidsansome/ \
		http://freebsd.ricin.com/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-QT Theme Engine allows GTK2 apps to use QT (KDE) themes

LIB_DEPENDS=	kdecore:${PORTSDIR}/x11/kdelibs3

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gtk20
USE_QT_VER=	3

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	GTK_VER=${GTK2_VERSION}
PLIST_SUB+=	LOCALBASE=${LOCALBASE}

CONFIGURE_ARGS+=--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include

OPTIONS=	BONOBOUI "With libbonoboui (recommended)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_BONOBOUI)
LIB_DEPENDS+=	bonoboui-2:${PORTSDIR}/x11-toolkits/libbonoboui
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|/usr/lib/menu|/tmp/menu|" \
		${WRKSRC}/kcm_gtk/Makefile
	@${REINPLACE_CMD} -e \
		"s|/usr/share/applications|${PREFIX}/share/applications/kde|g" \
		${WRKSRC}/kcm_gtk/Makefile

post-install:
	@${RM} /tmp/menu/kcmgtk.menu
	@if [ "`ls /tmp/menu`" = "" ]; then ${RMDIR} /tmp/menu; fi
	@${RM} ${PREFIX}/share/applnk/Settings/LookNFeel/kcmgtk.desktop

.include <bsd.port.post.mk>
