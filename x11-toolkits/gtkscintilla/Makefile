# New ports collection makefile for:	gtkscintilla
# Date created:				14 December 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkscintilla
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	moleskine
DISTNAME=	GtkScintilla-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wrapper for the Scintilla editing component

LIB_DEPENDS=	scintilla.1:${PORTSDIR}/x11-toolkits/scintilla

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes

do-install:
	${MKDIR} ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/scintilla
	${INSTALL_DATA} ${WRKSRC}/libgtkscintilla.a ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/libgtkscintilla.so.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libgtkscintilla.so.0 ${PREFIX}/lib/libgtkscintilla.so

.include <bsd.port.mk>
