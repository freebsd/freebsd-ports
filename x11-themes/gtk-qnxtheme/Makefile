# New ports collection makefile for:	qnxtheme
# Date created:         Thu Jan 30 13:27:44 CET 2003
# Whom:                 Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-qnxtheme
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://download.freshmeat.net/themes/qnxtheme/
DISTNAME=	qnxtheme-default-${PORTVERSION}

MAINTAINER=	flynn@energyhq.homeip.net
COMMENT=	QNX-inspired theme for GTK1 and GTK2

.if defined(WITH_GTK2)
LIB_DEPENDS+=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20
PLIST_SUB+=	GTK2=""
.else
PLIST_SUB+=	GTK2="@comment "
.endif

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/QNX

pre-everything::
	@${ECHO} ""
	@${ECHO} "By default only gtk-1.2 theme engine will be built."
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      WITH_GTK2=yes   Build gtk-2 theme"
	@${ECHO} ""

do-install:
	@${REINPLACE_CMD} -e 's@/usr@${X11BASE}@g' ${WRKSRC}/gtk/gtkrc
	@${REINPLACE_CMD} -e 's@QNX@qnxtheme@g' ${WRKSRC}/gtk/gtkrc
	@${RM} -f ${WRKSRC}/gtk/gtkrc.bak
	@${MKDIR} ${X11BASE}/share/themes/qnxtheme/gtk
	@for i in ${WRKSRC}/gtk/*; do \
		${INSTALL_DATA} $$i ${X11BASE}/share/themes/qnxtheme/gtk; \
	done
.if defined(WITH_GTK2)
	@${REINPLACE_CMD} -e 's@/usr@${X11BASE}@g' ${WRKSRC}/gtk-2.0/gtkrc
	@${REINPLACE_CMD} -e 's@QNX@qnxtheme@g' ${WRKSRC}/gtk-2.0/gtkrc
	@${RM} -f ${WRKSRC}/gtk-2.0/gtkrc.bak
	@${MKDIR} ${X11BASE}/share/themes/qnxtheme/gtk-2.0
	@for i in ${WRKSRC}/gtk-2.0/*; do \
		 ${INSTALL_DATA} $$i ${X11BASE}/share/themes/qnxtheme/gtk-2.0; \
	done
.endif

.include <bsd.port.mk>
