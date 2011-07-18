# New ports collection makefile for:	gnocl
# Date created:         15 August 2003
# Whom:                 Stephane Legrand <stephane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnocl
DISTVERSION=	${BASE_VERSION}-${NIGHTLY_BUILD}
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF/${PORTNAME}/Gnocl-Nightly-Build/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	GTK+ and Gnome extension for Tcl

LIB_DEPENDS=	canberra.0:${PORTSDIR}/audio/libcanberra \
   		notify.1:${PORTSDIR}/devel/libnotify

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20 libglade2 pkgconfig
USE_TCL=	84+
USE_LDCONFIG=	yes
CFLAGS+=	-I${TCL_INCLUDEDIR} -L${TCL_LIBDIR} `pkg-config --cflags libglade-2.0`

BASE_VERSION=	0.9.95
NIGHTLY_BUILD=	30-06-11

WRKSRC=		${WRKDIR}/${PORTNAME}-${BASE_VERSION}
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}

BASEDIR=	lib/${PORTNAME}${BASE_VERSION}
PLIST_FILES=	${BASEDIR}/${PORTNAME}.so \
		${BASEDIR}/pkgIndex.tcl
PLIST_DIRS=	${BASEDIR}

post-patch:
	${REINPLACE_CMD} -e 's|tclsh|${TCLSH}|;s|$$(TCL_VERSION)|${TCL_VER:S/.//}|g' ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|\[info library\]|${PREFIX}/lib|; s|tclsh|${TCLSH}|g;' ${BUILD_WRKSRC}/install.tcl

.include <bsd.port.mk>
