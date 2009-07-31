# New ports collection makefile for:	libgtksourceviewmm
# Date created:		2006-11-11
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11-toolkits/libgtksourceviewmm/Makefile,v 1.4 2008/08/08 21:59:44 kwm Exp $

PORTNAME=	libgtksourceviewmm
PORTVERSION=	1.9.5
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ binding of GtkSourceView

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_GNOME=	gtksourceview2 gnomeprefix gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBAS}/lib"
CONFIGURE_ARGS=	--disable-docs

.include <bsd.port.mk>
