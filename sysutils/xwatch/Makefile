# New ports collection makefile for:   	xwatch
# Date created:				17 July 1998
# Whom:					mph
#
# $FreeBSD$
#

PORTNAME=	xwatch
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.student.lu.se/~nbi98oli/src/obsolete/

MAINTAINER=	mph@freebsd.org
COMMENT=	A Gtk-based program for watching files (e.g. logs) in a window

USE_XLIB=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${PREFIX}/share/doc/xwatch
	${INSTALL_DATA} ${WRKSRC}/doc/xwatch.test.conf ${PREFIX}/share/doc/xwatch
.endif

.include <bsd.port.mk>
