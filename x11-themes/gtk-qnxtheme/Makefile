# New ports collection makefile for:	qnxtheme
# Date created:         Thu Jan 30 13:27:44 CET 2003
# Whom:                 Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	gtk-qnxtheme
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	3414-qnxtheme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QNX-inspired theme for GTK1 and GTK2

OPTIONS=	GTK2     "Build the GTK2 theme as well"     on

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GTK2)
PLIST_SUB+=	GTK2="@comment "
.else
USE_GNOME=	gtk20
PLIST_SUB+=	GTK2=""
.endif

post-patch:
.for file in gtk/gtkrc gtk-2.0/gtkrc
	@${REINPLACE_CMD} -i "" -e \
		's|/usr/share|${LOCALBASE}/share|g ; \
		 s|themes/QNX|themes/qnxtheme|g' ${WRKSRC}/QNX/${file}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/themes/qnxtheme
	${INSTALL_DATA} ${WRKSRC}/QNX/README ${PREFIX}/share/themes/qnxtheme
	@${MKDIR} ${PREFIX}/share/themes/qnxtheme/gtk
	@(cd ${WRKSRC}/QNX/gtk \
		&& ${COPYTREE_SHARE} . ${PREFIX}/share/themes/qnxtheme/gtk)
.if !defined(WITHOUT_GTK2)
	@${MKDIR} ${PREFIX}/share/themes/qnxtheme/gtk-2.0
	@(cd ${WRKSRC}/QNX/gtk-2.0 \
		&& ${COPYTREE_SHARE} . ${PREFIX}/share/themes/qnxtheme/gtk-2.0)
.endif

.include <bsd.port.post.mk>
