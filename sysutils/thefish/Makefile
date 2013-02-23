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

WANT_GNOME=	yes

OPTIONS_SINGLE=		X11
OPTIONS_SINGLE_X11=	GTK2 QT3
OPTIONS_DEFAULT=	GTK2

QT3_DESC=	Use Qt3 for the X11 interface

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
MAKE_ENV+=	WITH_GTK=yes
.endif

.if ${PORT_OPTIONS:MQT3}
USE_QT_VER=	3
MAKE_ENV+=	WITH_QT=yes
CXXFLAGS+=	-Wall -DWITH_QT -I${LOCALBASE}/include
.endif

MAN1=		thefish.1
PLIST_FILES=	bin/thefish

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
