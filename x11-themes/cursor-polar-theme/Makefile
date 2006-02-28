# New ports collection makefile for:	cursor-polar-theme
# Date created:				1st September, 2005
# Whom:					decept
#
# $FreeBSD$
#

PORTNAME=	cursor-polar-theme
PORTVERSION=	1.3
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.kde-look.org/content/files/ \
		http://dl.droso.net/FreeBSD/distfiles/
DISTNAME=	27913-PolarCursorTheme

MAINTAINER=	decept0@gmail.com
COMMENT=	Polar is a smooth and simple cursor set

NO_BUILD=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/PolarCursorTheme

do-install:
	${MKDIR} ${PREFIX}/lib/X11/icons/PolarCursorTheme/cursors
	cd ${WRKSRC}/cursors \
	&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/PolarCursorTheme/cursors

.include <bsd.port.mk>
