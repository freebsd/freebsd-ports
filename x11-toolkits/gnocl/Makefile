# New ports collection makefile for:	gnocl
# Date created:         15 August 2003
# Whom:                 Stephane Legrand <stephane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnocl
PORTVERSION=	0.5.15
PORTREVISION=	2
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	http://www.dr-baum.net/gnocl/

MAINTAINER=	stephane@FreeBSD.org
COMMENT=	GTK+ and Gnome extension for Tcl

BUILD_DEPENDS=	${LOCALBASE}/include/tcl8.4/tcl.h:${PORTSDIR}/lang/tcl84

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

BUILD_WRKSRC=	${WRKSRC}/src
CFLAGS+=	-I${LOCALBASE}/include/tcl8.4

USE_X_PREFIX=	yes
USE_GNOME=	gtk20

BROKEN=	"Does not build with gtk+-2.4"

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

GNOCL_CANVAS_FILE="lib/libgnoclCanvas.so.1"
GNOCL_GCONF_FILE="lib/libgnoclGconf.so.1"
GNOCL_GNOME_FILE="lib/libgnoclGnome.so.1"

.if defined(WITHOUT_CANVAS)
GNOCL_CANVAS_FILE=	"@comment "
.else
USE_GNOME+=	libgnomecanvas
.endif

.if defined(WITHOUT_GCONF)
GNOCL_GCONF_FILE=	"@comment "
.else
USE_GNOME+=	gconf2
.endif

.if defined(WITHOUT_GNOME)
GNOCL_GNOME_FILE=	"@comment "
.else
USE_GNOME+=	libgnomeui gnomepanel
.endif

PLIST_SUB+=	GNOCL_CANVAS_FILE=${GNOCL_CANVAS_FILE}
PLIST_SUB+=	GNOCL_GCONF_FILE=${GNOCL_GCONF_FILE}
PLIST_SUB+=	GNOCL_GNOME_FILE=${GNOCL_GNOME_FILE}

post-patch:
.if defined(WITHOUT_CANVAS)
	${REINPLACE_CMD} -e 's=^USE_CANVAS=#USE_CANVAS=' ${BUILD_WRKSRC}/Makefile
.endif
.if defined(WITHOUT_GCONF)
	${REINPLACE_CMD} -e 's=^USE_GCONF=#USE_GCONF=' ${BUILD_WRKSRC}/Makefile
.endif
.if defined(WITHOUT_GNOME)
	${REINPLACE_CMD} -e 's=^USE_GNOME=#USE_GNOME=' ${BUILD_WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/gnocl.so ${PREFIX}/lib/libgnocl.so.1
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclCanvas.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclCanvas.so ${PREFIX}/lib/libgnoclCanvas.so.1; \
	fi; \
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclGconf.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclGconf.so ${PREFIX}/lib/libgnoclGconf.so.1; \
	fi; \
	if ${TEST} -f ${BUILD_WRKSRC}/gnoclGnome.so; then \
		${INSTALL_DATA} ${BUILD_WRKSRC}/gnoclGnome.so ${PREFIX}/lib/libgnoclGnome.so.1; \
	fi; \

.include <bsd.port.post.mk>
