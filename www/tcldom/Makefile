# New ports collection makefile for:	TclDOM
# Date created:				28 April 2008
# Whom:					Frank Fenor <frank@fenor.de>
#
# $FreeBSD$
#

PORTNAME=	tcldom
DISTVERSION=	3.1
CATEGORIES=	www tcl
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	tclxml

MAINTAINER=	frank@fenor.de
COMMENT=	DOM API for Tcl based on TclDOMPro

BUILD_DEPENDS?=	${LOCALBASE}/include/expat.h:${PORTSDIR}/textproc/expat2

WRKSRC?=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/src
USE_TCL=	82+
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I\"${PREFIX}/include\""
PLIST_FILES=	lib/tcldom2.0/tcldom84.so.1 lib/tcldom2.0/pkgIndex.tcl

.include <bsd.port.mk>
