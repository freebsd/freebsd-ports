# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webkit
PORTVERSION=	2.4.11
PORTREVISION=	18
CATEGORIES=	www
MASTER_SITES=	https://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk3
DISTNAME=	${PORTNAME}gtk-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Opensource browser engine using the GTK+ 3 toolkit

BUILD_DEPENDS=	gtkdoc-rebase:textproc/gtk-doc \
		p5-Switch>0:lang/p5-Switch \
		geoclue>=0:net/geoclue
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libsecret-1.so:security/libsecret \
		libicutu.so:devel/icu \
		libharfbuzz.so:print/harfbuzz \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libwebp.so:graphics/webp \
		libcurl.so:ftp/curl \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	geoclue>=0:net/geoclue

DEPRECATED=	Known and unfixed security issues
EXPIRATION_DATE=2019-03-24
FORBIDDEN=	Known and unfixed security issues

PORTSCOUT=	limit:^2\.4\.

BINARY_ALIAS=	python=${PYTHON_CMD}
USE_GSTREAMER1=	yes
USE_XORG=	xt xdamage xcomposite
USES=		bison compiler:c++11-lib gettext gl gmake gnome gperf libtool localbase \
		pathfix perl5 pkgconfig python:build shebangfix sqlite tar:xz
PATHFIX_MAKEFILEIN=	GNUmakefile.in
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=yes
USE_GNOME=	cairo gtk20 gtk30 introspection:build libxslt
USE_GL=		gl
USE_PERL5=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	AR=/usr/bin/ar \
		ac_cv_path_DOLT_BASH=""
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-gtk=3.0 \
		--enable-svg-fonts \
		--enable-geolocation \
		--enable-webkit2 \
		--enable-introspection
MAKEFILE=	GNUmakefile
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

BROKEN_sparc64=	fails to detect working compiler

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

.if ${ARCH} == i386 && ! ${CFLAGS:M-march=*}
# Needed for __atomic_fetch_add_8
CFLAGS+=	-march=i586
.endif

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-c++11-extensions	# Shutup warning spam
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
		${STAGEDIR}${PREFIX}/bin/GtkLauncher-3
	${INSTALL_PROGRAM} ${WRKSRC}/Programs/MiniBrowser \
		${STAGEDIR}${PREFIX}/bin/MiniBrowser-3

.include <bsd.port.post.mk>
