# New ports collection makefile for:	thefish
# Date created:			Sat Mar 16 17:49:09 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	thefish
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.energyhq.es.eu.org/files/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Gtk+/ncurses rc.conf editor/management tool

.if defined(WITHOUT_X11) || defined(NO_GUI)
NO_GUI=		yes
MAKE_ENV+=	NO_GUI=yes
.else
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
.endif

MAN1=		thefish.1

pre-everything::
.if !defined(WITHOUT_X11) && !defined(NO_GUI)
	@${CAT} ${PKGMESSAGE}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
