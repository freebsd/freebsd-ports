# New ports collection makefile for:	amule
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/amule/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	The all-platform eMule p2p client

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24 \
		curl.3:${PORTSDIR}/ftp/curl

CONFLICTS=	aMule-devel-*

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnomehack gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-wx-config=${WX_CONFIG} \
		--with-wxbase-config=${WX_CONFIG} \
		--with-curl-config=${CURL_CONFIG} \
		--program-transform-name="s/ed2k/amule-ed2k-handler/"

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	OPTIMIZE "Build with optimization" on \
		STATIC "Enable static linking" off

WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
CURL_CONFIG?=	${LOCALBASE}/bin/curl-config

.include <bsd.port.pre.mk>

# Configure options
.if !defined(WITHOUT_OPTIMIZE)
CONFIGURE_ARGS+=	--enable-optimise
.endif

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--enable-static
.endif

.include <bsd.port.post.mk>
