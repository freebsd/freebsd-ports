# New ports collection makefile for:   gtk20-apireference
# Date created:        13 June 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	gtk20-apireference
PORTVERSION=	20021119
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://developer.gnome.org/doc/API/
DISTFILES=	glib-2.0-docs.tar.gz gtk-2.0-docs.tar.gz gdk-2.0-docs.tar.gz

MAINTAINER=	edwin@mavetju.org

NO_BUILD=	yes
PREFIX=		${X11BASE}

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gdk20
	@${MKDIR} ${PREFIX}/share/doc/gtk20
	@${MKDIR} ${PREFIX}/share/doc/glib20
	${CP} -R ${WRKDIR}/gdk/* ${PREFIX}/share/doc/gdk20
	${CP} -R ${WRKDIR}/glib/* ${PREFIX}/share/doc/glib20
	${CP} -R ${WRKDIR}/gtk/* ${PREFIX}/share/doc/gtk20

.include <bsd.port.mk>
