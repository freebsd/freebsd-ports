# New ports collection makefile for:	acidlaunch
# Date created:				11 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	acidlaunch
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An application launcher with simple XML-based configuration syntax

HAS_CONFIGURE=	yes
USE_GNOME=	gtk12 gdkpixbuf libxml2
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN1=		${PORTNAME}.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
.for file in config.xml default.png
	${INSTALL_DATA} ${WRKSRC}/prefs/${file} ${PREFIX}/share/${PORTNAME}
.endfor
	@${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
