# New ports collection makefile for:	gnocl
# Date created:         15 August 2003
# Whom:                 Stephane Legrand <stephane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnocl
PORTVERSION=	0.5.12
PORTREVISION=	1
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://www.dr-baum.net/gnocl/

MAINTAINER=	stephane@FreeBSD.org
COMMENT=	GTK+ and Gnome extension for Tcl

BUILD_DEPENDS=	${LOCALBASE}/include/tcl8.4/tcl.h:${PORTSDIR}/lang/tcl84

USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes

BUILD_WRKSRC=	${WRKSRC}/src
CFLAGS+=	-I${LOCALBASE}/include/tcl8.4

USE_X_PREFIX=	yes
USE_GNOME=	libgnomecanvas gconf2

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

GNOCL_CANVAS_FILE="lib/libgnoclCanvas.so.1"

.if defined(WITHOUT_CANVAS)
ALL_TARGET=	gnocl
USE_GNOME=	gtk20 gconf2
GNOCL_CANVAS_FILE=	"@comment "
.endif

.if defined(WITH_GNOME)
GNOCL_USE_GNOME:=1
USE_GNOME+=	libgnomeui
.endif

PLIST_SUB+=	GNOCL_CANVAS_FILE=${GNOCL_CANVAS_FILE}

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/gnocl.so ${PREFIX}/lib/libgnocl.so.1
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclCanvas.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclCanvas.so ${PREFIX}/lib/libgnoclCanvas.so.1; \
	fi; \

.include <bsd.port.post.mk>
