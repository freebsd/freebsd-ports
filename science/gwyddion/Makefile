# Created by: Yeti <yeti@gwyddion.net>
# $FreeBSD$

PORTNAME=	gwyddion
PORTVERSION=	2.30
PORTREVISION=	2
CATEGORIES=	science graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gtk2 based SPM data visualization and analysis tool

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		cairo:${PORTSDIR}/graphics/cairo \
		IlmThread:${PORTSDIR}/graphics/ilmbase \
		drm:${PORTSDIR}/graphics/libdrm \
		png15:${PORTSDIR}/graphics/png \
		fftw3:${PORTSDIR}/math/fftw3 \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext \
		xcb:${PORTSDIR}/x11/libxcb

OPTIONS_DEFINE=	PERL PYTHON RUBY UNIQUE
OPTIONS_DEFAULT=PERL PYTHON UNIQUE
UNIQUE_DESC=	Remote controle backend support

USE_XZ=		yes
USE_GNOME=	desktopfileutils gconf2 gnomehack gnomemimedata gtk20 libxml2
USE_XORG=	ice pixman sm x11 xau xcomposite xcursor xdamage xdmcp xext \
		xfixes xi xinerama xmu xrandr xrender xt xxf86vm
USE_GL=		glu
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules --disable-gtk-doc \
		--disable-pygwy --without-gtksourceview \
		--without-kde4-thumbnailer
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gwyddion-thumbnailer.schemas

MAN1=		gwyddion.1 gwyddion-thumbnailer.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
MAN3+=		Gwyddion::dump.3pm
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
USE_RUBY=	yes
PLIST_SUB+=	RUBY=""
.else
CONFIGURE_ARGS+=--without-ruby
PLIST_SUB+=	RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	unique-1.0:${PORTSDIR}/x11-toolkits/unique
.else
CONFIGURE_ARGS+=--without-unique
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|thumbnailer \\|thumbnailer| ; \
		 s|devel-docs$$||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
