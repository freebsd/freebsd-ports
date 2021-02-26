# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libproxy
DISTVERSION=	0.4.17
PORTREVISION?=	0
CATEGORIES?=	net devel

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	Library that provides automatic proxy configuration management

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES+=		cmake cpe pathfix pkgconfig
CPE_VENDOR=	libproxy_project
PATHFIX_CMAKELISTSTXT=	devfiles.cmk
USE_GITHUB=	yes

CMAKE_ON+=	WITH_VALA
CMAKE_OFF+=	BIPR WITH_DOTNET WITH_NATUS WITH_NM WITH_NMold

# Slave ports.
LIBPROXY_SLAVES=	library gnome3 kde mozjs python perl webkit3

# If nothing is set, we're building the library, i.e. this port.
LIBPROXY_SLAVE?=	library

PLIST_SUB+=	VERSION=${PORTVERSION}

# Activate the wanted module, and deactivate the others
CMAKE_ON+=	WITH_${LIBPROXY_SLAVE:tu}
CMAKE_OFF+=	${LIBPROXY_SLAVES:N${LIBPROXY_SLAVE}:tu:S/^/WITH_/}

# Setup slave ports.
.if ${LIBPROXY_SLAVE:Nlibrary}
USES+=		localbase
LIB_DEPENDS+=	libproxy.so:net/libproxy
DESCR=		${.CURDIR:H}/${PORTNAME}-${LIBPROXY_SLAVE}/pkg-descr
PLIST=		${.CURDIR:H}/${PORTNAME}-${LIBPROXY_SLAVE}/pkg-plist
.endif

.if ${LIBPROXY_SLAVE:Mwebkit3}
# Additionally to WITH_WEBKIT3 also WITH_WEBKIT is required.
CMAKE_ON+=	WITH_WEBKIT
CMAKE_OFF:=	${CMAKE_OFF:C/WITH_WEBKIT//}
.endif

.if ${LIBPROXY_SLAVE:Mpacrunner}
LIB_DEPENDS+=	 libdbus-1.so:devel/dbus
CMAKE_ON=	BUILD_CONFIG_PACRUNNER
.endif

.if ${LIBPROXY_SLAVE:Mkde} || ${LIBPROXY_SLAVE:Mwebkit3}
RUN_DEPENDS+=	libproxy-pacrunner>=${DISTVERSION}:net/libproxy-pacrunner
.endif

.include <bsd.port.pre.mk>

# Hackery for the to python backends.
.if ${LIBPROXY_SLAVE:Mpython}
CMAKE_ON+=		WITH_PYTHON3
CMAKE_OFF+=		WITH_PYTHON2
CMAKE_ARGS+=		-DPYTHON3_EXECUTABLE:FILEPATH=${PYTHON_CMD}
.else
CMAKE_OFF+=		WITH_PYTHON2 WITH_PYTHON3
.endif

.include <bsd.port.post.mk>
