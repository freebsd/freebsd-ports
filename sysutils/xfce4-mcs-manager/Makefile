# New ports collection makefile for:	xfce-mcs-manager
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mcs-manager
PORTVERSION=	4.0.5
PORTREVISION=	0
CATEGORIES=	sysutils xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DISTNAME=	xfce-mcs-manager-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings manager

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xfce4mcs-manager.1:${PORTSDIR}/x11/libxfce4mcs

USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/xfce-mcs-manager/Makefile.in

.include <bsd.port.mk>
