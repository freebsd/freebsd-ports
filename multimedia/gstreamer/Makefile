# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer/Makefile,v 1.74 2010/03/09 10:11:45 kwm Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.10.36
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Development framework for creating media applications

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

CFLAGS:=	${CFLAGS} -O2 -Wno-format
USES=		bison gettext gmake pathfix pkgconfig
USE_BZIP2=	yes
USE_GNOME=	glib20 introspection libxml2 ltverhack ltasneededhack
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-failing-tests \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	ac_cv_func_register_printf_function="no"
PLIST_SUB=	VERSION="${GST_VERSION}"
USE_LDCONFIG=	yes
GST_VERSION=	0.10

OPTIONS_DEFINE=	LIBCHECK
LIBCHECK_DESC=	Unit tests support

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBCHECK}
LIB_DEPENDS+=	libcheck.so:${PORTSDIR}/devel/libcheck
PLIST_SUB+=	CHECK=""
.else
CONFIGURE_ARGS+=--disable-check
PLIST_SUB+=	CHECK="@comment "
.endif

# workaround a crash in clang 3.3 crash llvm bug # 15840
.if ((${OSVERSION} >= 901504 && ${OSVERSION} < 902502) || \
     (${OSVERSION} >= 1000037 && ${OSVERSION} < 1000056))
USE_GCC=	any
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgst*.so*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-0.10/libgst*.so

.include <bsd.port.post.mk>
