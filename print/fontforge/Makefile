# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	fontforge
PORTVERSION=	20150824
PORTREVISION=	2
CATEGORIES=	print
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash \
		${LOCALBASE}/bin/gnulib-tool:devel/gnulib
LIB_DEPENDS=	libuninameslist.so:textproc/libuninameslist \
		libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libgif.so:graphics/giflib \
		libspiro.so:graphics/libspiro \
		libfreetype.so:print/freetype2 \
		libltdl.so:devel/libltdl

USE_GITHUB=	yes

USES=		autoreconf:build desktop-file-utils execinfo gettext gmake iconv \
		jpeg libtool pkgconfig python shared-mime-info shebangfix
SHEBANG_FILES=	pycontrib/gdraw/__init__.py \
		pycontrib/gdraw/gdraw.py
USE_XORG=	ice x11 xi xkbui
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
MASTER_SITES+=	http://savannah.nongnu.org/download/freetype/:freetype \
		SF/freetype/freetype2/${FREETYPE_VERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/}/:freetype \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype2/:freetype \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/:freetype \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/:freetype \
		ftp://ftp.freetype.org/freetype/freetype2/:freetype
FREETYPE_VERSION=	2.6.2
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
		export LIBTOOLIZE=true ; ${AUTORECONF} -f -i)

.include <bsd.port.mk>
