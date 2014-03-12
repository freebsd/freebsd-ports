# $FreeBSD$
#    $MCom: ports/sysutils/consolekit/Makefile,v 1.25 2010/10/23 10:12:30 kwm Exp $

PORTNAME=	consolekit
PORTVERSION=	0.4.3
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.freedesktop.org/software/ConsoleKit/dist/
DISTFILES=	ConsoleKit-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for defining and tracking users

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
    		polkit-gobject-1.0:${PORTSDIR}/sysutils/polkit

WRKSRC=		${WRKDIR}/ConsoleKit-${PORTVERSION}
USE_BZIP2=	yes
USE_XORG=	x11
USES=		pathfix gettext pkgconfig gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pid-file=/var/run/${PORTNAME}.pid \
		--localstatedir=/var

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-display-device \
		${STAGEDIR}${PREFIX}/libexec/ck-get-x11-display-device
	${INSTALL_SCRIPT} ${FILESDIR}/ck-get-x11-server-pid \
	    	${STAGEDIR}${PREFIX}/libexec/ck-get-x11-server-pid
	${MKDIR} ${STAGEDIR}/var/log/ConsoleKit
	${TOUCH} ${STAGEDIR}/var/log/ConsoleKit/history

.include <bsd.port.mk>
