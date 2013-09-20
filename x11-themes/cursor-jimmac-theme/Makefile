# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	cursor-jimmac-theme
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	6550-Jimmac

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	The beautiful Jimmac X cursor themes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Jimmac

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/Jimmac/cursors
	cd ${WRKSRC}/jimmac/cursors \
		&& ${INSTALL_DATA} * ${PREFIX}/lib/X11/icons/Jimmac/cursors

.include <bsd.port.mk>
