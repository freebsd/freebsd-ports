# New ports collection makefile for:	amule
# Date created:		Wed Nov 05 09:30:00 UTC 2003
# Whom:			Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	aMule
PORTVERSION=	1.2.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://download.berlios.de/amule/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Just another eMule P2P Client

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2 \
		curl.2:${PORTSDIR}/ftp/curl

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnomehack gnomeprefix
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-libintl-prefix=${LOCALBASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-wx-config=${WX_CONFIG} \
		--with-wxbase-config=${WX_CONFIG}

OPTIONS=	OPTIMIZE "Build with optimization" off \
		STATIC "Enable static linking" off \
		RELGRP "Use release group code" off

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config

# Configure options
.if defined(WITH_OPTIMIZE)
CONFIGURE_ARGS+=	--enable-optimise
.endif

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=	--enable-static
.endif

.if defined(WITH_RELGRP)
CONFIGURE_ARGS+=	--enable-releasegrp
.endif

post-build:
# Build the generic named ed2k binary
# It will be installed in an adhoc fashion
	@cd ${BUILD_WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ed2k

post-install:
# Do not install a generic named ed2k binary
# Install it under a more specific name
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ed2k \
		${PREFIX}/bin/amule-ed2k-handler

.include <bsd.port.mk>
