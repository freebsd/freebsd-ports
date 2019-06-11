# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	fontforge
PORTVERSION=	20190413
CATEGORIES=	print

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
		libltdl.so:devel/libltdl \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf:build compiler desktop-file-utils gettext \
		gmake gnome iconv jpeg libtool pkgconfig python \
		readline:port shared-mime-info shebangfix
USE_GITHUB=	yes
USE_XORG=	ice sm x11 xi xkbui xft
USE_GNOME=	cairo glib20 gtk20 libxml2 pango

SHEBANG_FILES=	pycontrib/gdraw/__init__.py \
		pycontrib/gdraw/gdraw.py

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

FREETYPE_PATCH_DEPENDS=	${NONEXISTENT}:print/freetype2:extract
FREETYPE_CONFIGURE_ENABLE=	freetype-debugger=${WRKSRC}/freetype

CAIRO_CONFIGURE_WITH=	cairo

PYTHON_CONFIGURE_ENABLE=	python-scripting python-extension

post-patch-FREETYPE-on:
	@${LN} -s $$(${MAKE} -C ${PORTSDIR}/print/freetype2 -V WRKSRC) ${WRKSRC}/freetype

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
