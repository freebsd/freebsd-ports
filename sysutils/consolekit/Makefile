# New ports collection makefile for:	ConsoleKit
# Date Created:				26 Aug 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/consolekit/Makefile,v 1.23 2009/09/26 12:32:45 kwm Exp $

PORTNAME=	consolekit
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/ConsoleKit/dist/
DISTFILES=	ConsoleKit-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
    		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

WRKSRC=		${WRKDIR}/ConsoleKit-${PORTVERSION}
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XORG=	x11
USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid \
		--localstatedir=/var

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-display-device \
	    	${PREFIX}/libexec/ck-get-x11-display-device
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-server-pid \
	    	${PREFIX}/libexec/ck-get-x11-server-pid
	${MKDIR} /var/log/ConsoleKit
	${TOUCH} /var/log/ConsoleKit/history

.include <bsd.port.mk>
