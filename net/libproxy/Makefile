# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net/libproxy/Makefile,v 1.1 2011/01/12 13:10:52 kwm Exp $

PORTNAME=	libproxy
PORTVERSION=	0.4.12
PORTREVISION?=	0
CATEGORIES?=	net devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	Library that provides automatic proxy configuration management

CPE_VENDOR=		libproxy_project
PATHFIX_CMAKELISTSTXT=	devfiles.cmk
USE_GITHUB=		yes
USES+=			cmake:outsource cpe pathfix

PLIST_SUB+=	VERSION=${PORTVERSION}

CMAKE_ARGS=	-DBIPR:BOOL=OFF -DWITH_DOTNET:BOOL=OFF \
		-DWITH_NATUS:BOOL=OFF -DWITH_NM:BOOL=OFF \
		-DWITH_VALA:BOOL=ON

.if !defined(LIBPROXY_SLAVE)
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DWITH_PYTHON:BOOL=OFF -DWITH_PERL:BOOL=OFF \
		-DWITH_GNOME2:BOOL=OFF -DWITH_GNOME3:BOOL=OFF \
		-DWITH_KDE:BOOL=OFF -DWITH_MOZJS:BOOL=OFF \
		-DWITH_WEBKIT:BOOL=OFF -DWITH_WEBKIT3:BOOL=OFF
.else
PORTSCOUT=	ignore:1

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
CMAKE_ARGS+=	-DWITH_GNOME2:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_GNOME2:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="gnome3"
CMAKE_ARGS+=	-DWITH_GNOME3:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_GNOME3:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="kde"
CMAKE_ARGS+=	-DWITH_KDE:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_KDE:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="webkit"
CMAKE_ARGS+=	-DWITH_WEBKIT3:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_WEBKIT3:BOOL=OFF -DWITH_WEBKIT:BOOL=OFF
. endif

. if ${LIBPROXY_SLAVE}=="mozjs"
CMAKE_ARGS+=	-DWITH_MOZJS:BOOL=ON
. else
CMAKE_ARGS+=	-DWITH_MOZJS:BOOL=OFF
. endif
.endif

.include <bsd.port.mk>
