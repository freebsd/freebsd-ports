# Created by: Shawn Bell <decept@gmail.com>
# $FreeBSD$

PORTNAME=	polar-theme
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
PKGNAMEPREFIX=	cursor-
DISTNAME=	27913-PolarCursorThemes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Polar is a smooth and simple cursor set

NO_BUILD=	yes
USES=	tar:bzip2

WRKSRC=		${WRKDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/polar/cursors
	${INSTALL_DATA} ${WRKSRC}/PolarCursorTheme/cursors/* \
		${STAGEDIR}${PREFIX}/share/icons/polar/cursors

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/polarblue/cursors
	${INSTALL_DATA} ${WRKSRC}/PolarCursorTheme-Blue/cursors/* \
		${STAGEDIR}${PREFIX}/share/icons/polarblue/cursors

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/polargreen/cursors
	${INSTALL_DATA} ${WRKSRC}/PolarCursorTheme-Green/cursors/* \
		${STAGEDIR}${PREFIX}/share/icons/polargreen/cursors

.include <bsd.port.mk>
