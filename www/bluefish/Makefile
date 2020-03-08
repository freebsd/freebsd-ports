# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	bluefish
PORTVERSION=	2.2.10
PORTREVISION=	3
CATEGORIES=	www editors
MASTER_SITES=	http://www.bennewitz.com/bluefish/stable/source/ \
		http://bluefish.mrball.net/stable/source/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	HTML editor designed for the experienced web designer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libenchant.so:textproc/enchant

USES=		desktop-file-utils gettext gmake gnome libtool localbase \
		pkgconfig python:2.7 shared-mime-info shebangfix tar:bzip2
SHEBANG_FILES=	data/css_decompressor data/cssmin.py data/jsbeautify \
		data/jsmin.py data/lorem-ipsum-generator
python_OLD_CMD=	/usr/bin/python2.7
USE_GNOME=	cairo intltool libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-freedesktop_org-menu=${PREFIX}/share/applications \
		--with-freedesktop_org-mime=${PREFIX}/share/mime \
		--with-icon-path=${PREFIX}/share/pixmaps \
		--disable-update-databases
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DEBUG DOCS TIDY
OPTIONS_SINGLE=	TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	GTK2 GTK3
OPTIONS_DEFAULT=GTK3
OPTIONS_SUB=	yes

TOOLKIT_DESC=		GTK+ toolkit

DEBUG_CONFIGURE_ENABLE=	debugging-output
GTK2_USE=		gnome=gtk20
GTK2_CONFIGURE_ON=	--with-gtk2=yes
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK3_LIB_DEPENDS=	libgucharmap_2_90.so:deskutils/gucharmap
GTK3_USE=		gnome=gtk30
TIDY_RUN_DEPENDS=	tidy4:www/tidy

.include <bsd.port.mk>
