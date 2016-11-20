# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer/Makefile,v 1.74 2010/03/09 10:11:45 kwm Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.10.36
PORTREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Development framework for creating media applications

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:0\.10\..*

CFLAGS:=	${CFLAGS} -O2 -Wno-format
USES=		bison gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20 introspection libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-failing-tests \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	ac_cv_func_register_printf_function="no"
PLIST_SUB=	VERSION="${GST_VERSION}"
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
GST_VERSION=	0.10

OPTIONS_DEFINE=	LIBCHECK NLS
OPTIONS_SUB=	yes
LIBCHECK_DESC=	Unit tests support

LIBCHECK_LIB_DEPENDS=	libcheck.so:devel/libcheck
LIBCHECK_CONFIGURE_OFF=	--disable-check

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.pre.mk>

# workaround a crash in clang 3.3 crash llvm bug # 15840
.if ((${OSVERSION} >= 901504 && ${OSVERSION} < 902502) || \
     (${OSVERSION} >= 1000037 && ${OSVERSION} < 1000056))
USE_GCC=	any
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
