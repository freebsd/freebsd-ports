# New ports collection makefile for:	stuphead
# Date created:		07 December 2000
# Whom:			Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	stuphead
PORTVERSION=	0.5.2
CATEGORIES=	mail gnome
MASTER_SITES=	http://stuphead.antex.ru/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}.patch

MAINTAINER=	ozz@FreeBSD.org.ru

LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-threads \
		--prefix=${PREFIX}

.if defined (WITH_PIXBUF)
LIB_DEPENDS+=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
.else
CONFIGURE_ARGS+=	--disable-gdk-pixbuf \
			--disable-gdk_pixbuftest
.endif

.if defined (WITH_GNOME)
USE_GNOME=	yes
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-imlib \
			--disable-imlibtest
.endif

.if defined (WITH_MOZILLA)
CONFIGURE_ARGS+=	--enable-mozilla
BUILD_DEPENDS+=	${PREFIX}/include/mozilla/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers
RUN_DEPENDS+=	${PREFIX}/bin/mozilla:${PORTSDIR}/www/mozilla
.endif

.if defined (WITH_ISPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell-ru:${PORTSDIR}/russian/rus-ispell
.endif

pre-patch:
	@${PERL} -pi -e 's#DATADIRNAME=lib#DATADIRNAME=share#g' \
		${WRKSRC}/configure
	@${PERL} -pi -e 's#/usr/bin/gnome-config#$(PREFIX)/bin/gnome-config#g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
