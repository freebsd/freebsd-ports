# New ports collection makefile for:    vtk
# Version required:     2.3
# Date created:         24 Nov 1997
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=       vtk23unix
PKGNAME=	vtk-2.3
CATEGORIES=	math
MASTER_SITES=	ftp://vtk.scorec.rpi.edu/pub/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3	\
		tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		$(WRKDIR)/vtk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mesa --with-shared --with-tcl --with-bsdmake
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CXXFLAGS="${CFLAGS}"

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
