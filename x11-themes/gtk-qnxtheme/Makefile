# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	gtk-qnxtheme
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	3414-qnxtheme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QNX-inspired theme for GTK1 and GTK2

NO_ARCH=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	GTK2
OPTIONS_DEFAULT=	GTK2
OPTIONS_SUB=	yes

GTK2_DESC=	Build the GTK2 theme as well
GTK2_USE=	GNOME=gtk20

post-patch:
.for file in gtk/gtkrc gtk-2.0/gtkrc
	@${REINPLACE_CMD} -i "" -e \
		's|/usr/share|${LOCALBASE}/share|g ; \
		 s|themes/QNX|themes/qnxtheme|g' ${WRKSRC}/QNX/${file}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/qnxtheme
	${INSTALL_DATA} ${WRKSRC}/QNX/README ${STAGEDIR}${PREFIX}/share/themes/qnxtheme
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/qnxtheme/gtk
	@(cd ${WRKSRC}/QNX/gtk \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/themes/qnxtheme/gtk)

do-install-GTK2-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/qnxtheme/gtk-2.0
	@(cd ${WRKSRC}/QNX/gtk-2.0 \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/themes/qnxtheme/gtk-2.0)

.include <bsd.port.mk>
