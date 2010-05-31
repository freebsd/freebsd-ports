# New ports collection makefile for:	totem-pl-parser
# Date created:		2007-12-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/totem-pl-parser/Makefile,v 1.35 2010/04/01 18:58:58 kwm Exp $
#

PORTNAME=	totem-pl-parser
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject-based library to parse a host of playlist formats

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal \
		gmime-2.4.6:${PORTSDIR}/mail/gmime24
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomevfs2 intlhack ltverhack
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
