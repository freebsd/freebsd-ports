# Created by: Babak Farrokhi <babak@farrokhi.net>
# $FreeBSD$

PORTNAME=	gtk-envy-theme
PORTVERSION=	1.0.${SNAPSHOT}
PORTREVISION=	8
CATEGORIES=	x11-themes gnome
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	60029-Envy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Envy theme for GTK+ 2.0

#RUN_DEPENDS=	${LOCALBASE}/share/icons/Tango:x11-themes/icons-tango

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_GNOME=	gtk20

SNAPSHOT=	20060211

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/Envy
	${INSTALL_DATA} ${FILESDIR}/index.theme.in \
		${STAGEDIR}${PREFIX}/share/themes/Envy/index.theme
	@(cd ${WRKSRC}/Envy \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/themes/Envy)

.include <bsd.port.mk>
