# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	fontforge
DISTVERSION=	20150430
CATEGORIES=	print
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:${PORTSDIR}/devel/uthash \
		${LOCALBASE}/bin/gnulib-tool:${PORTSDIR}/devel/gnulib
LIB_DEPENDS=	libuninameslist.so:${PORTSDIR}/textproc/libuninameslist \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libspiro.so:${PORTSDIR}/graphics/libspiro \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libltdl.so:${PORTSDIR}/devel/libltdl

USE_GITHUB=	yes

USES=		autoreconf:build desktop-file-utils execinfo gettext gmake iconv \
		jpeg libtool pkgconfig python shared-mime-info
USE_XORG=	x11 xi ice xkbui
USE_GNOME=	glib20 gtk20 libxml2 pango

CONFIGURE_ARGS=	--enable-tile-path --enable-gtk2-use
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

PORTDOCS=	* .htaccess

OPTIONS_DEFINE=	DOCS FREETYPE CAIRO PYTHON
OPTIONS_SUB=	yes
FREETYPE_DESC=	Include freetype's internal debugger

PYTHON_CONFIGURE_ENABLE=	python-scripting python-extension

CAIRO_USE=	GNOME=cairo
CAIRO_CONFIGURE_WITH=	cairo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
MASTER_SITES+=	http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/:freetype \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/:freetype \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/:freetype \
		ftp://ftp.freetype.org/freetype/freetype2/:freetype
FREETYPE_VERSION=	2.5.5
FREETYPE_SRC=	freetype-${FREETYPE_VERSION}.tar.bz2
DISTFILES+=	${FREETYPE_SRC:C/$/:freetype/}
CONFIGURE_ARGS+=	--enable-freetype-debugger=${WRKDIR}/freetype-${FREETYPE_VERSION}
.else
CONFIGURE_ARGS+=	--disable-freetype-debugger
.endif

# This is to get around calling fontforge's bootstrap script, as that script fails
# if git isn't installed on a system DESPITE there being a --skip-git argument that
# can be passed into it. autoreconf is called here because I want to run it without
# libtoolize being run along with it.
pre-configure:
	(cd ${WRKSRC} && \
		${SH} -c '. ./bootstrap.conf ; \
		${LOCALBASE}/bin/libtoolize -i -c -q ; \
		${LOCALBASE}/bin/gnulib-tool --aux-dir=config --m4-base=m4 --libtool --symlink --import $${gnulib_modules}' ; \
		export LIBTOOLIZE=true ; ${LOCALBASE}/bin/autoreconf -s -i)

.include <bsd.port.mk>
