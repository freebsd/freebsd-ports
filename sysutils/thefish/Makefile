# New ports collection makefile for:	thefish
# Date created:			Sat Mar 16 17:49:09 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	thefish
PORTVERSION=	0.6.5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.energyhq.es.eu.org/files/

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	Qt/Gtk+/ncurses rc.conf editor/management tool

MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}" \
		X11BASE="${X11BASE}"

WANT_GNOME=	yes

OPTIONS=	CONSOLE "Disable X11 support" off \
		GTK	"Use GTK+ for the X11 interface" on \
		QT	"Use Qt for the X11 interface" off

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

# Honour legacy WITHOUT_X11 and NO_GUI and support new options
.if defined(WITHOUT_X11) || defined(NO_GUI) || defined(WITH_CONSOLE)
NO_GUI=		yes
MAKE_ENV+=	NO_GUI=yes
.endif

.if defined(WITH_GTK) || !defined(WITHOUT_GTK)
USE_GNOME=	gtk20
MAKE_ENV+=	WITH_GTK=yes
.endif

.if defined(WITH_QT)
USE_QT_VER=	3
MAKE_ENV+=	WITH_QT=yes
CXXFLAGS+=	-Wall -DWITH_QT -I${X11BASE}/include
.endif

MAN1=		thefish.1
PLIST_FILES=	bin/thefish

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
