# New ports collection makefile for:	ConsoleKit
# Date Created:				26 Aug 2006
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/consolekit/Makefile,v 1.12 2008/02/27 15:13:25 ahze Exp $

PORTNAME=	consolekit
PORTVERSION=	0.2.10
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://people.freedesktop.org/~mccann/dist/
DISTFILES=	ConsoleKit-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
    		polkit.2:${PORTSDIR}/sysutils/policykit

WRKSRC=		${WRKDIR}/ConsoleKit-${PORTVERSION}
USE_XORG=	x11
USE_GNOME=	gnomehack gnometarget
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

.include <bsd.port.mk>
