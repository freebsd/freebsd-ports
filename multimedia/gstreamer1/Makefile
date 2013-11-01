# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer1/Makefile,v 1.5 2013/01/15 21:43:45 kwm Exp $

PORTNAME=	gstreamer1
PORTVERSION=	1.0.10
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/
DISTNAME=	${PORTNAME:S/1//}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Media applications framework

LICENSE=	LGPL20

PORTSCOUT=	limitw:1,even

CFLAGS:=	${CFLAGS} -O2 -Wno-format
USES=		bison gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	glib20 gnomehier introspection:build ltverhack:0 ltasneededhack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-failing-tests \
		--disable-fatal-warnings \
		--disable-gtk-doc
#--enable-gst-debug --enable-debug
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	ac_cv_func_register_printf_function="no"
PLIST_SUB=	VERSION=${GST10_VERSION}
USE_LDCONFIG=	yes
GST10_VERSION=	${PORTVERSION:R}

OPTIONS_DEFINE=	LIBCHECK
LIBCHECK_DESC=	Unit tests support

.include <bsd.port.options.mk>

# workaround a crash in clang 3.3 crash llvm bug # 15840
.if ((${OSVERSION} >= 901504 && ${OSVERSION} < 902502) || \
     (${OSVERSION} >= 1000037 && ${OSVERSION} < 1000056))
USE_GCC=	any
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

.if ${PORT_OPTIONS:MLIBCHECK}
LIB_DEPENDS+=	libcheck.so:${PORTSDIR}/devel/libcheck
CONFIGURE_ARGS+=--enable-check
PLIST_SUB+=	CHECK=""
.else
CONFIGURE_ARGS+=--disable-check
PLIST_SUB+=	CHECK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgst*-1.0.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/libgst*.so

.include <bsd.port.mk>

