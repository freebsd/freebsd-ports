# New ports collection makefile for:	gtkscintilla
# Date created:				14 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/gtkscintilla/Makefile,v 1.1 2006/10/04 15:42:01 ahze Exp $

PORTNAME=	gtkscintilla
PORTVERSION=	0.8.2
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/moleskine/GtkScintilla/${PORTVERSION}
DISTNAME=	GtkScintilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper for the Scintilla editing component

LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla

BROKEN=		depends on x11-toolkits/scintilla which no longer supports gtk12
DEPRECATED=	no longer under development, last release in 2002
EXPIRATION_DATE=	2009-10-13

USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LDCONFIG=	yes

pre-configure:
	@if [ -n "`${PKG_INFO} -E 'scintilla-gtk2-[0-9]*' 2> /dev/null`" ]; then \
		${ECHO_CMD} "${PKGNAME}: requires x11-toolkits/scintilla to be built with GTK+1."; \
		${FALSE}; \
	fi

do-install:
	${MKDIR} ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/libgtkscintilla.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libgtkscintilla.so.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libgtkscintilla.so.0 ${PREFIX}/lib/libgtkscintilla.so

.include <bsd.port.mk>
