# Created by: Shawn Bell <decept@gmail.com>
# $FreeBSD$

PORTNAME=	polar-theme
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	cursor-
DISTNAME=	27913-PolarCursorThemes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Polar is a smooth and simple cursor set

NO_BUILD=	yes
USE_BZIP2=	yes

WRKSRC=		${WRKDIR}

NO_STAGE=	yes
do-install:
		@${MKDIR} ${PREFIX}/lib/X11/icons/polar/cursors
		cd ${WRKSRC}/PolarCursorTheme/cursors \
			&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/polar/cursors

		@${MKDIR} ${PREFIX}/lib/X11/icons/polarblue/cursors
		cd ${WRKSRC}/PolarCursorTheme-Blue/cursors \
			&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/polarblue/cursors

		@${MKDIR} ${PREFIX}/lib/X11/icons/polargreen/cursors
		cd ${WRKSRC}/PolarCursorTheme-Green/cursors \
			&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/polargreen/cursors

.include <bsd.port.mk>
