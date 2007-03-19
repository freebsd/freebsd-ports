# New ports collection makefile for:	libgtksourceviewmm
# Date created:		2006-11-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/libgtksourceviewmm/Makefile,v 1.2 2006/12/06 00:54:45 ahze Exp $

PORTNAME=	libgtksourceviewmm
PORTVERSION=	0.2.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ binding of GtkSourceView

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GNOME=	gtksourceview gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${WRKSRC}/gtksourceview/ \
			`pkg-config --cflags gtkmm-2.4 gtksourceview-1.0`" \
		LDFLAGS="-L${LOCALBAS}/lib \
			`pkg-config --libs gtkmm-2.4 gtksourceview-1.0`"

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
