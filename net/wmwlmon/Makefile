# Created by: Marcus Glocker <marcus@nazgul.ch>
# $FreeBSD$

PORTNAME=	wmwlmon
PORTVERSION=	1.0
CATEGORIES=	net windowmaker
MASTER_SITES=	http://www.nazgul.ch/dev/

MAINTAINER=	LukeD@pobox.com
COMMENT=	DockApp showing the state of a wireless network device

USES=		xorg
USE_XORG=	x11 xext xpm

PLIST_FILES=	bin/wmwlmon man/man1/wmwlmon.1.gz

post-patch:
	${REINPLACE_CMD} -e 's#/usr/X11R6#${LOCALBASE}#g' \
		-e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmwlmon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmwlmon.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
