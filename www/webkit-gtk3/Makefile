# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/webkit-gtk3/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	webkit
PORTVERSION=	2.4.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

# Use the port>=0 form or the system gperf version will get 
# detected instead, breaking the build.

BUILD_DEPENDS=	gperf>=0:${PORTSDIR}/devel/gperf \
		gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc \
		geoclue>=0:${PORTSDIR}/net/geoclue
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libsecret-1.so:${PORTSDIR}/security/libsecret \
		libicutu.so:${PORTSDIR}/devel/icu \
		libharfbuzz.so:${PORTSDIR}/print/harfbuzz \
		libwebp.so:${PORTSDIR}/graphics/webp \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	geoclue>=0:${PORTSDIR}/net/geoclue 

USE_GSTREAMER1=	yes
USE_XORG=	xt xdamage xcomposite
USES=		bison gettext gmake libtool perl5 pkgconfig \
		shebangfix tar:xz
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gnomehier gtk20 gtk30 introspection:build \
		libxslt:build
USE_SQLITE=	3
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_DOLT_BASH=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-gtk=3.0 \
		--enable-svg-fonts \
		--enable-geolocation \
		--enable-introspection
MAKEFILE=	GNUmakefile
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

#CONFIGURE_ARGS+=--disable-silent-rules
CONFIGURE_ARGS+=--disable-egl \
		--disable-gles2
#		--with-acceleration-backend=opengl # clutter broken?
# opengl, clutter, none (clutter unsupported)

SHEBANG_FILES=	\
	Source/JavaScriptCore/create_hash_table \
	Source/JavaScriptCore/inspector/scripts/xxd.pl \
	Source/WebCore/css/*.pl \
	Source/WebCore/dom/*.pl \
	Source/WebCore/make-hash-tools.pl \
	Source/WebCore/page/make_settings.pl \
	Source/WebCore/platform/text/mac/make-charset-table.pl \
	Source/WebKit2/Scripts/generate-forwarding-headers.pl \
	Source/WebCore/bindings/scripts/*.p[lm] \
	Source/JavaScriptCore/create_hash_table

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk3
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	WEBGL WEBAUDIO DEBUG FULLDEBUG
OPTIONS_DEFAULT=WEBGL WEBAUDIO
WEBAUDIO_DESC=	Web audio support
WEBGL_DESC=	Enable Web GL support
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable asserts and other debug support

WEBGL_CONFIGURE_ENABLE=	webgl
WEBGL_USE=	GL=gl
WEBAUDIO_CONFIGURE_ENABLE=	web-audio
FULLDEBUG_CONFIGURE_ENABLE=	debug
DEBUG_CONFIGURE_ON=	--enable-debug-symbols=yes
DEBUG_CONFIGURE_OFF=	--disable-debug-symbols

.include <bsd.port.options.mk>

# gtest to use <tr1/tuple,> while libc++ only has <tuple>
CPPFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE
# Shutup warning spam
CXXFLAGS+=	-Wno-c++11-extensions -Qunused-arguments

CONFIGURE_ARGS+=--enable-webkit2
# We need clang + libc++ or gcc 4.7+. gcc has libstdc++ conflict between
# gcc port and base. This originates from icu
CXXFLAGS+=	-stdlib=libc++
LDFLAGS+=	-stdlib=libc++
.if ${OSVERSION}<1000019
BUILD_DEPENDS+=	clang33>=3.3_1:${PORTSDIR}/lang/clang33 \
		libc++>=0:${PORTSDIR}/devel/libc++
RUN_DEPENDS+=	libc++>=0:${PORTSDIR}/devel/libc++
CC=		clang33
CXX=		clang++33
CPP=		clang-cpp33
CONFIGURE_ENV+=	CC=${CC} CXX=${CXX} CPP=${CPP}
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+=	p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=0:${PORTSDIR}/textproc/flex
CONFIGURE_ENV+=	FLEX_PATH="${LOCALBASE}/bin/flex"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp
	@${FIND} ${WRKSRC} -name GNUmakefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	@${REINPLACE_CMD} -e 's|"gperf|"${LOCALBASE}/bin/gperf|g' \
		${WRKSRC}/Source/WebCore/css/makevalues.pl \
		${WRKSRC}/Source/WebCore/css/makeprop.pl \
		${WRKSRC}/Source/WebCore/make-hash-tools.pl

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/GtkLauncher \
		${STAGEDIR}${PREFIX}/bin/GtkLauncher-3
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/MiniBrowser \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
