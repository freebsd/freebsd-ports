# New ports collection makefile for:	libproxy
# Date created:		26 February 2009
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net/libproxy/Makefile,v 1.1 2011/01/12 13:10:52 kwm Exp $

PORTNAME=	libproxy
PORTVERSION=	0.4.6
PORTREVISION?=	0
CATEGORIES?=	net devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Library that provides automatic proxy configuration management

USES+=		cmake

PLIST_SUB+=	VERSION=${PORTVERSION}

.if !defined(LIBPROXY_SLAVE)
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF  -DWITH_PERL:BOOL=OFF \
		-DWITH_GNOME:BOOL=OFF -DWITH_KDE4:BOOL=OFF \
		-DWITH_WEBKIT:BOOL=OFF -DWITH_MOZJS:BOOL=OFF \
		-DWITH_NETWORKMANAGER:BOOL=OFF -DWITH_VALA:BOOL=ON
.else

# Libproxy is build for the slave ports, since I haven't been able to find
# out how to only build optional code with cmake.
# Patches for this problem are welcome.

. if ${LIBPROXY_SLAVE}=="python"
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="perl"
CMAKE_ARGS+=	-DWITH_PERL:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_PERL:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="gnome"
CMAKE_ARGS+=	-DWITH_GNOME:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_GNOME:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="kde"
CMAKE_ARGS+=	-DWITH_KDE4:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_KDE4:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="webkit"
CMAKE_ARGS+=	-DWITH_WEBKIT:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_WEBKIT:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="mozjs"
CMAKE_ARGS+=	-DWITH_MOZJS:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_MOZJS:BOOL=OFF
. endif
.endif

post-install:
	@${MKDIR} ${PREFIX}/lib/libproxy/${PORTVERSION}/modules/

.include <bsd.port.mk>
