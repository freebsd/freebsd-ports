# New ports collection makefile for:	midori
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/midori/Makefile,v 1.10 2008/12/31 03:30:21 mezz Exp $
#

PORTNAME=	midori
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Lightweight web browser using WebKit browser engine

LIB_DEPENDS=	webkit-1.0:${PORTSDIR}/www/webkit-gtk2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		soup-2.4:${PORTSDIR}/devel/libsoup
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		rsvg-convert:${PORTSDIR}/graphics/librsvg2

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-unique

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool libxml2 pkgconfig
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

# WAF needs that
CONFIGURE_ENV+=	CC="${CC=gcc}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
