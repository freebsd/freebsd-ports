# New ports collection makefile for:   gtk12-apireference
# Date created:        13 December 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	gtk12-apireference
PORTVERSION=	20021119
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://developer.gnome.org/doc/API/
DISTFILES=	glib-docs.tar.gz gtk-docs.tar.gz gdk-docs.tar.gz

MAINTAINER=	edwin@mavetju.org
COMMENT=	API reference for the Gimp Toolkit for X11 GUI

NO_BUILD=	yes
PREFIX=		${X11BASE}

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gdk12
	@${MKDIR} ${PREFIX}/share/doc/gtk12
	@${MKDIR} ${PREFIX}/share/doc/glib12
	${CP} -R ${WRKDIR}/gdk/* ${PREFIX}/share/doc/gdk12
	${CP} -R ${WRKDIR}/glib/* ${PREFIX}/share/doc/glib12
	${CP} -R ${WRKDIR}/gtk/* ${PREFIX}/share/doc/gtk12

.include <bsd.port.mk>
