# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	gtk-qnxtheme
PORTVERSION=	0.1
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	3414-qnxtheme-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QNX-inspired theme for GTK2

USES=		gnome
USE_GNOME=	gtk20

NO_ARCH=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -i "" -e \
		's|/usr/share|${LOCALBASE}/share|g ; \
		 s|themes/QNX|themes/qnxtheme|g' ${WRKSRC}/QNX/gtk-2.0/gtkrc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/qnxtheme/gtk-2.0
	${INSTALL_DATA} ${WRKSRC}/QNX/README ${STAGEDIR}${PREFIX}/share/themes/qnxtheme
	@(cd ${WRKSRC}/QNX/gtk-2.0 \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/themes/qnxtheme/gtk-2.0)

.include <bsd.port.mk>
