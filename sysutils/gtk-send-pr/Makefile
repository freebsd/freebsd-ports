# New ports collection makefile for:	gtk-send-pr
# Date created:			Fri May  2 22:08:08 CEST 2003
# Whom:				Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-send-pr
PORTVERSION=	0.4.7
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/${PORTNAME}/

MAINTAINER=	mmendez@energyhq.be
COMMENT=	GTK2 send-pr tool

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

USE_GNOME=	gtk20
USE_X_PREFIX=	yes

MAN1=		gtk-send-pr.1
PLIST_FILES=	bin/gtk-send-pr share/pixmaps/ladybird64.xpm
DESKTOP_ENTRIES="Send Problem Report" \
		"Send a FreeBSD PR" \
		"ladybird64.xpm" \
		"gtk-send-pr" \
		"Application;System;" \
		true

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk-send-pr ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/gtk-send-pr.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/ladybird64.xpm ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
