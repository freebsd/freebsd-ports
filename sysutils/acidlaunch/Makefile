# New ports collection makefile for:	acidlaunch
# Date created:				11 Apr 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	acidlaunch
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://linuxgamers.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application launcher with simple XML-based configuration syntax

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12 gdkpixbuf libxml2

PLIST_FILES=	bin/${PORTNAME} %%DATADIR%%/config.xml %%DATADIR%%/default.png
PLIST_DIRS=	%%DATADIR%%
MAN1=		${PORTNAME}.1

post-extract:
	@${REINPLACE_CMD} -e 's/enum GdkWMDecoration/GdkWMDecoration/' \
		${WRKSRC}/src/launcherwindow.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/prefs/config.xml \
		${WRKSRC}/prefs/default.png ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
