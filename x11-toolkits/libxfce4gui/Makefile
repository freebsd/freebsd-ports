# New ports collection makefile for:	libxfce4util
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	libxfce4gui
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce-${PORTVERSION}/src/ \
                ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/xfce-${PORTVERSION}/src/ \
                http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/${PORTVERSION}/ \
                http://www.efd.lth.se/~c03bk/xfce4/mirror/tarballs/${PORTVERSION}/
DISTNAME=	libxfcegui4-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 widget library required by xfce4 and xfwm4

LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util

USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-xinerama
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libxfcegui4/Makefile.in

.include <bsd.port.mk>
