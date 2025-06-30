PORTNAME=	bluefish
DISTVERSION=	2.2.17
PORTREVISION=	1
CATEGORIES=	www editors
MASTER_SITES=	https://www.bennewitz.com/bluefish/stable/source/ \
		SF

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer
WWW=		http://bluefish.openoffice.nl/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libgucharmap_2_90.so:deskutils/gucharmap \
		libharfbuzz.so:print/harfbuzz \
		libpcre2-8.so:devel/pcre2

USES=		desktop-file-utils gettext-tools gmake gnome libtool localbase \
		pkgconfig python shared-mime-info shebangfix tar:bzip2
USE_GNOME=	cairo gdkpixbuf gtk30 intltool libxml2
SHEBANG_FILES=	data/css_decompressor data/cssmin.py data/jsmin.py \
		data/json_prettyprint.py data/lorem-ipsum-generator \
		src/plugin_zencoding/zencoding/*.py \
		src/plugin_zencoding/zencoding/actions/*.py \
		src/plugin_zencoding/zencoding/filters/*.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-update-databases \
		--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps
INSTALL_TARGET=	install-strip

PORTSCOUT=	skipv:2.2.15fp

OPTIONS_DEFINE=	DEBUG DOCS NLS TIDY
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ENABLE=	debugging-output

NLS_CONFIGURE_ENABLE=	nls

TIDY_RUN_DEPENDS=	tidy4:www/tidy

.include <bsd.port.mk>
