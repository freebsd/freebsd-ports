# Created by: Piotr Smyrak <smyru@heron.pl>
# $FreeBSD$

PORTNAME=	cursor-jimmac-theme
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.gnome-look.org/CONTENT/content-files/
DISTNAME=	6550-Jimmac

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	The beautiful Jimmac X cursor themes

BROKEN=		unfetchable

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Jimmac

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/Jimmac/cursors
	cd ${WRKSRC}/jimmac/cursors \
		&& ${INSTALL_DATA} * ${STAGEDIR}${PREFIX}/share/icons/Jimmac/cursors

.include <bsd.port.mk>
