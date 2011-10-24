# New ports collection makefile for: net-p2p/eiskaltdc
# Date created:		28 Aug 2009
# Whom:			Stas Timokhin <stast@bsdportal.ru>
#
# $FreeBSD$
#

PORTNAME=	eiskaltdcpp-gtk
PORTVERSION=	2.2.4
CATEGORIES=	net-p2p
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	eiskaltdcpp-${DISTVERSION}

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	EiskaltDC++ Direct Connect client GTK GUI

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/share/eiskaltdcpp/keep_me:${PORTSDIR}/net-p2p/eiskaltdcpp-data
LIB_DEPENDS=	eiskaltdcpp:${PORTSDIR}/net-p2p/eiskaltdcpp-lib

CMAKE_ARGS+=	-DBUILD_LIB:BOOL=OFF
PROJECTHOST=	eiskaltdc

USE_XZ=		yes
USE_GCC=	4.4+
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1
MANCOMPRESSED=	yes

OPTIONS=	MINIUPNP	"UPnP support"	on \
		LIBGNOME2	"Sound notification support"	off \
		LIBNOTIFY	"Popup notification support"	on

USE_GNOME=	pango gtk20 glib20

CMAKE_ARGS+=	-DUSE_QT:BOOL=OFF
CMAKE_ARGS+=	-DUSE_GTK:BOOL=ON
CMAKE_ARGS+=	-DEISKALTDCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/eiskaltdcpp"
CMAKE_ARGS+=	-DCREATE_MO:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib:${PREFIX}/lib"
CMAKE_ARGS+=	-DCMAKE_SKIP_RPATH:BOOL=ON
CMAKE_ARGS+=	-DINSTALL_DATA:BOOL=OFF

.include <bsd.port.options.mk>

.if defined(WITH_MINIUPNP)
LIB_DEPENDS+=	miniupnpc:${PORTSDIR}/net/miniupnpc
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=ON -DLOCAL_MINIUPNP:BOOL=OFF
.else
CMAKE_ARGS+=	-DUSE_MINIUPNP:BOOL=OFF
.endif

.if defined(WITH_LIBGNOME2)
USE_GNOME+=	libgnome
CMAKE_ARGS+=	-DUSE_LIBGNOME2:BOOL=ON
.else
CMAKE_ARGS+=	-DUSE_LIBGNOME2:BOOL=OFF
.endif

.if defined(WITH_LIBNOTIFY)
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CMAKE_ARGS+=	-DUSE_LIBNOTIFY:BOOL=ON
.else
CMAKE_ARGS+=	-DUSE_LIBNOTIFY:BOOL=OFF
.endif

.if ${OSVERSION} < 700024
USE_OPENSSL_PORT=yes
.endif

.include <bsd.port.mk>
