# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	thefish
PORTVERSION=	0.6.6
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt/Gtk+/ncurses rc.conf editor/management tool

MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

WANT_GNOME=	yes

OPTIONS_DEFINE=	X11
OPTIONS_SINGLE=	X11
OPTIONS_SINGLE_X11=	GTK2 QT3
OPTIONS_DEFAULT=	X11 GTK2

QT3_DESC=	Use Qt3 for the X11 interface

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
MAKE_ENV+=	NO_GUI=yes
.endif

.if ${PORT_OPTIONS:MX11} && ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
MAKE_ENV+=	WITH_GTK=yes
.endif

.if ${PORT_OPTIONS:MX11} && ${PORT_OPTIONS:MQT3}
USE_QT_VER=	3
MAKE_ENV+=	WITH_QT=yes
CXXFLAGS+=	-Wall -DWITH_QT -I${LOCALBASE}/include
.endif

MAN1=		thefish.1
PLIST_FILES=	bin/thefish

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.mk>
