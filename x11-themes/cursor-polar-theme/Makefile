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

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/icons/polar/cursors
	${INSTALL_DATA} ${WRKSRC}/PolarCursorTheme/cursors/* \
		${STAGEDIR}${PREFIX}/lib/X11/icons/polar/cursors

	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/icons/polarblue/cursors
	${INSTALL_DATA} ${WRKSRC}/PolarCursorTheme-Blue/cursors/* \
		${STAGEDIR}${PREFIX}/lib/X11/icons/polarblue/cursors

	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/icons/polargreen/cursors
	${INSTALL_DATA} ${WRKSRC}/PolarCursorTheme-Green/cursors/* \
		${STAGEDIR}${PREFIX}/lib/X11/icons/polargreen/cursors

.include <bsd.port.mk>
