PORTNAME=	bluefish
DISTVERSION=	2.2.14
PORTREVISION=	2
CATEGORIES=	www editors
MASTER_SITES=	https://www.bennewitz.com/bluefish/stable/source/ \
		SF

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer
WWW=		http://bluefish.openoffice.nl/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libharfbuzz.so:print/harfbuzz \
		libpcre2-8.so:devel/pcre2

USES=		desktop-file-utils gettext gmake gnome libtool localbase \
		pkgconfig python:3.8-3.9 shared-mime-info shebangfix tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 intltool libxml2
SHEBANG_FILES=	data/css_decompressor data/cssmin.py data/jsbeautify \
		data/jsmin.py data/lorem-ipsum-generator \
		src/plugin_zencoding/zencoding/actions/*.py \
		src/plugin_zencoding/zencoding/filters/*.py \
		src/plugin_zencoding/zencoding/*.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-databases \
		--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DEBUG DOCS NLS TIDY
OPTIONS_DEFAULT=	GTK3
OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_SUB=		yes

TOOLKIT_DESC=	GTK toolkit

DEBUG_CONFIGURE_ENABLE=	debugging-output
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_USE=		GNOME=gtk20
GTK2_CONFIGURE_ON=	--with-gtk2=yes

GTK3_LIB_DEPENDS=	libgucharmap_2_90.so:deskutils/gucharmap
GTK3_USE=		GNOME=gtk30

NLS_CONFIGURE_ENABLE=	nls

TIDY_RUN_DEPENDS=	tidy4:www/tidy

.include <bsd.port.mk>
