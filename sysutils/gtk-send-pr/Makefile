# New ports collection makefile for:	gtk-send-pr
# Date created:			Fri May  2 22:08:08 CEST 2003
# Whom:				Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-send-pr
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.energyhq.es.eu.org/files/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	GTK2 send-pr tool

LIB_DEPENDS=	esmtp.6:${PORTSDIR}/mail/libesmtp

USE_GNOME=	gtk20
USE_X_PREFIX=	yes

MAN1=		gtk-send-pr.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/gtk-send-pr ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/gtk-send-pr.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
