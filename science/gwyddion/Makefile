# Created by: Yeti <yeti@gwyddion.net>
# $FreeBSD$

PORTNAME=	gwyddion
PORTVERSION=	2.51
PORTREVISION=	3
CATEGORIES=	science graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 based SPM data visualization and analysis tool

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libminizip.so:archivers/minizip \
		libcfitsio.so:astro/cfitsio \
		libIlmImf.so:graphics/openexr \
		libfftw3.so:math/fftw3 \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		compiler:c++11-lang desktop-file-utils gl gmake gnome libtool \
		localbase:ldflags pathfix pkgconfig shared-mime-info shebangfix \
		tar:xz xorg
SHEBANG_FILES=	plugins/process/invert_python.py
USE_GNOME=	cairo gtk20 libxml2 pangox-compat
USE_GL=		gl glu
USE_XORG=	ice sm x11 xmu xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--without-pascal \
		--without-kde4-thumbnailer
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		GCONF NLS PERL PYTHON RUBY UNIQUE
OPTIONS_DEFAULT=	GCONF PERL PYTHON UNIQUE
OPTIONS_SUB=		yes

GCONF_CONFIGURE_OFF=	--disable-schemas-install
GCONF_USE=		GNOME=gconf2
GCONF_VARS=		GCONF_SCHEMAS=gwyddion-thumbnailer.schemas
NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext
PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl
PYTHON_USES=		python:2.7
PYTHON_USE=		gnome=pygtksourceview
PYTHON_CONFIGURE_ENABLE=	pygwy
PYTHON_CONFIGURE_WITH=	gtksourceview python
RUBY_USE=		ruby=yes
RUBY_CONFIGURE_WITH=	ruby
UNIQUE_DESC=		Remote control backend support
UNIQUE_LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique
UNIQUE_CONFIGURE_WITH=	unique

post-patch:
	@${REINPLACE_CMD} -e \
		's|thumbnailer \\|thumbnailer| ; \
		 s|devel-docs$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
