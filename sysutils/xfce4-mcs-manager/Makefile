# New ports collection makefile for:	xfce-mcs-manager
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mcs-manager
PORTVERSION=	3.99.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xfce.org/archive/xfce4-rc2/src/ \
		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/rc2/separate/ \
		http://usuarios.lycos.es/xfce4/tarballs/rc2/separate/ \
		http://linux.imp.mx/xfce4/rc2/xfce4-rc2/src/
DISTNAME=	xfce-mcs-manager-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFce 4 settings manager

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xfce4mcs-manager.1:${PORTSDIR}/x11/libxfce4mcs

USE_GNOME=	glib20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

post-patch:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/xfce-mcs-manager/Makefile.in

.include <bsd.port.mk>
