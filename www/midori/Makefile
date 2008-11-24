# New ports collection makefile for:	midori
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/www/midori/Makefile,v 1.3 2008/03/21 18:31:39 ahze Exp $

PORTNAME=	midori
PORTVERSION=	0.1.0
CATEGORIES=	www
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LIB_DEPENDS=	WebKitGtk.1:${PORTSDIR}/www/webkit-gtk2
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		rsvg-convert:${PORTSDIR}/graphics/librsvg2

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/WebKit/webkit -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-unique \
		--disable-gio \
		--disable-sqlite

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool libxml2 pkgconfig
INSTALLS_ICONS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
