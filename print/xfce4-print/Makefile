# New ports collection makefile for:	xfprint
# Date created:		7 June 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-print
PORTVERSION=	4.2.1
PORTREVISION=	0
CATEGORIES=	print xfce
MASTER_SITES=	http://www.us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://www.ca-us.xfce.org/archive/xfce-${PORTVERSION}/src/ \
		http://public.fh-wolfenbuettel.de/~luedickj/xfce4/xfce-${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DISTNAME=	xfprint-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 graphical frontend for printing

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xfce4mcs-client.2:${PORTSDIR}/x11/libxfce4mcs
RUN_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib
OPTIONS=	LPR	"Use lpr as printing system"	on\
		CUPS	"Use cups as printing system"	off

.if defined(WITH_CUPS)
CONFIGURE_ARGS+=--enable-cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
PLIST_SUB+=	CUPS=""
.else
CONFIGURE_ARGS+=--disable-cups
PLIST_SUB+=	CUPS="@comment "
.endif

.if defined(WITHOUT_LPR)
CONFIGURE_ARGS+=--disable-bsdlpr
PLIST_SUB+=	LPR="@comment "
.else
CONFIGURE_ARGS+=--enable-bsdlpr
PLIST_SUB+=	LPR=""
.endif

.if defined(WITH_LETTER)
CONFIGURE_ARGS+=--enable-letter
BUILD_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-letter
.else
CONFIGURE_ARGS+=--disable-letter
BUILD_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-a4
RUN_DEPENDS+=	a2ps:${PORTSDIR}/print/a2ps-a4
.endif

.include <bsd.port.mk>
