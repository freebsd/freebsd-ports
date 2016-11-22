# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	2.4.11
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk2
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 2 toolkit

BUILD_DEPENDS=	gtkdoc-rebase:textproc/gtk-doc \
		p5-Switch>0:lang/p5-Switch \
		python:lang/python \
		geoclue>=0:net/geoclue
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libsecret-1.so:security/libsecret \
		libicutu.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libwebp.so:graphics/webp \
		libcurl.so:ftp/curl \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	geoclue>=0:net/geoclue

PORTSCOUT=	limit:^2\.4\.

USE_GSTREAMER1=	yes
USE_XORG=	xt xdamage xcomposite
USES=		bison compiler:c++11-lib gettext gmake gperf libtool localbase \
		pathfix perl5 pkgconfig shebangfix sqlite tar:xz
PATHFIX_MAKEFILEIN=	GNUmakefile.in
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gtk20 introspection:build libxslt
USE_GL=		gl
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	AR=/usr/bin/ar \
		ac_cv_path_DOLT_BASH=""
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--enable-svg-fonts \
		--enable-geolocation \
		--enable-introspection \
		--disable-webkit2 \
		--with-html-dir=${PREFIX}/share/gtk-doc/html/webkit1
MAKEFILE=	GNUmakefile
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

BROKEN_sparc64=	attempts to use x86 assembler

CONFIGURE_ARGS+=--disable-egl \
		--disable-gles2
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

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk2
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	DEBUG FULLDEBUG
DEBUG_DESC=	Just enable debug symbols
FULLDEBUG_DESC=	Enable asserts and other debug support

FULLDEBUG_CONFIGURE_ENABLE=	debug
DEBUG_CONFIGURE_ON=	--enable-debug-symbols=yes
DEBUG_CONFIGURE_OFF=	--disable-debug-symbols

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>=0:textproc/flex
CONFIGURE_ENV+=	FLEX="${LOCALBASE}/bin/flex"
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-c++11-extensions # Shutup warning spam
CXXFLAGS+=	-Qunused-arguments
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp
# Since ruby 2.2 there is no ruby symlink
	@${REINPLACE_CMD} -e 's|ruby|${RUBY_NAME}|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/GtkLauncher \
		${STAGEDIR}${PREFIX}/bin/GtkLauncher-1

.include <bsd.port.post.mk>
