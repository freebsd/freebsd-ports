# New ports collection makefile for:	TclDOM
# Date created:				28 April 2008
# Whom:					Frank Fenor <frank@fenor.de>
#
# $FreeBSD$
#

PORTNAME=	tcldom
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	www tcl
MASTER_SITES=	SF/tclxml/TclDOM/${PORTVERSION}

MAINTAINER=	frank@fenor.de
COMMENT=	DOM API for Tcl based on TclDOMPro

BUILD_DEPENDS?=	${LOCALBASE}/include/expat.h:${PORTSDIR}/textproc/expat2

PLIST=		${PKGDIR}${PKGNAMESUFFIX}/pkg-plist
PATCHDIR=	${PKGDIR}${PKGNAMESUFFIX}/files/
WRKSRC?=	${WRKDIR}/${PORTNAME}-${DISTVERSION}/src
USE_TCL=	82+
INVALID_TCL_VER=	85 86
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I\"${PREFIX}/include\""

.include <bsd.port.mk>
