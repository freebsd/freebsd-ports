# New ports collection makefile for:	thefish
# Date created:			Sat Mar 16 17:49:09 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	thefish
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://www.energyhq.es.eu.org/files/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Qt/Gtk+/ncurses rc.conf editor/management tool

.if defined(WITHOUT_X11) || defined(NO_GUI)
NO_GUI=		yes
MAKE_ENV+=	NO_GUI=yes
.else
.if !defined(WITH_QT)
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
.endif
.endif
.if defined(WITH_QT)
USE_QT_VER=	3
MAKE_ENV+=	WITH_QT=yes
CXXFLAGS+=	-Wall -DWITH_QT -I${X11BASE}/include
.endif

MAN1=		thefish.1
PLIST_FILES=	bin/thefish

pre-everything::
.if !defined(WITHOUT_X11) && !defined(NO_GUI)
	@${CAT} ${PKGMESSAGE}
.endif
.if !defined(WITH_QT) && !defined(NO_GUI) && !defined(WITHOUT_X11)
	@${ECHO_CMD} "- You can replace the GTK+ interface with a Qt version by defining WITH_QT"
	@${ECHO_CMD}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
