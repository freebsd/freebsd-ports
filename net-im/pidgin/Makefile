# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/pidgin/Makefile,v 1.17 2007/09/17 19:53:06 marcus Exp $

PORTNAME=	pidgin

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Pidgin multi-protocol messaging client (GTK+ UI)

LIB_DEPENDS=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libpurple.so:${PORTSDIR}/net-im/libpurple

MASTERDIR=	${.CURDIR}/../libpurple
BUILD_WRKSRC=	${WRKSRC}/pidgin
INSTALL_WRKSRC=	${BUILD_WRKSRC}
INSTALLS_ICONS=	yes
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

PIDGIN_SLAVE=	yes
WITH_GTKUI=	yes

USE_LDCONFIG=	yes
USE_GNOME=	gnomeprefix intlhack gtk20
USE_XORG=	xscrnsaver sm
WANT_GNOME=	yes
CONFIGURE_ARGS=	--disable-consoleui \
		--disable-nm \
		--enable-screensaver \
		--with-dynamic_prpls=${PRPL_MODULES:S/,$//}

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
	    	Makefile ${MAKE_ARGS} pidgin.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/pidgin.desktop \
	    	${STAGEDIR}${PREFIX}/share/applications/pidgin.desktop
	${INSTALL_MAN} ${WRKSRC}/doc/pidgin.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
