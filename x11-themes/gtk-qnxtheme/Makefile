# New ports collection makefile for:	qnxtheme
# Date created:         Thu Jan 30 13:27:44 CET 2003
# Whom:                 Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-qnxtheme
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	qnxtheme
DISTNAME=	qnxtheme-default-${PORTVERSION}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	QNX-inspired theme for GTK1 and GTK2

WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/QNX

OPTIONS+=	GTK2	"Build the GTK2 theme as well." off

.include	<bsd.port.pre.mk>

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
PLIST_SUB+=	GTK2=""
.else
PLIST_SUB+=	GTK2="@comment "
.endif

# XXX - port build fails unless I create dummy file if OPTIONS aren't yet set
post-extract:
	@${ECHO_CMD} "all:" > ${WRKSRC}/Makefile

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

.include <bsd.port.post.mk>
