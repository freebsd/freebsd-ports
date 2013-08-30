# Created by: Stephane Legrand <stephane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnocl
DISTVERSION=	${BASE_VERSION}-${NIGHTLY_BUILD}
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF/${PORTNAME}/Gnocl-Nightly-Build/

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	GTK+ and Gnome extension for Tcl

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/license.terms

LIB_DEPENDS=	canberra:${PORTSDIR}/audio/libcanberra \
   		notify:${PORTSDIR}/devel/libnotify \
		gtkimageview:${PORTSDIR}/x11-toolkits/gtkimageview

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20 libglade2
USE_TCL=	84+
USE_LDCONFIG=	yes
CFLAGS+=	-I${TCL_INCLUDEDIR} -L${TCL_LIBDIR}

BASE_VERSION=	0.9.96
NIGHTLY_BUILD=	31-01-13

WRKSRC=		${WRKDIR}/${PORTNAME}-${BASE_VERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

BASEDIR=	lib/${PORTNAME}${BASE_VERSION}
PLIST_FILES=	${BASEDIR}/${PORTNAME}.so \
		${BASEDIR}/pkgIndex.tcl
PLIST_DIRS=	${BASEDIR}

post-patch:
	${REINPLACE_CMD} -e 's|tclsh|${TCLSH}|; \
	    s|%%LOCALBASE%%|${LOCALBASE}|; \
	    s|%%SHORT_TCL_VER%%|${TCL_VER:S/.//}|' \
	    ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|\[info library\]|${PREFIX}/lib|; s|tclsh|${TCLSH}|g;' ${BUILD_WRKSRC}/install.tcl

.include <bsd.port.mk>
