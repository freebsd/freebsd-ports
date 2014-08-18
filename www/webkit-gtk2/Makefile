# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/www/webkit-gtk2/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	webkit
PORTVERSION=	1.8.3
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/releases/
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An opensource browser engine

# Use the port>=0 form or the system versions of flex and gperf 
# will be detected instead, breaking the build.

BUILD_DEPENDS=	flex>=0:${PORTSDIR}/textproc/flex \
		gperf>=0:${PORTSDIR}/devel/gperf \
		gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libicutu.so:${PORTSDIR}/devel/icu \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USE_GSTREAMER=	yes
USE_XORG=	xt
USES=		bison gettext gmake libtool perl5 pkgconfig tar:xz
USE_GNOME=	gtk20 libxslt introspection:build
USE_SQLITE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_FLEX="${LOCALBASE}/bin/flex" \
		ZLIB_CFLAGS="-I/usr/include" \
		ZLIB_LIBS="-L/usr/lib -lz" \
		ac_cv_path_DOLT_BASH=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--enable-svg-fonts \
		--disable-geolocation \
		--enable-introspection
MAKEFILE=	GNUmakefile

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk2
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS_DEFINE=	WEBGL DEBUG
OPTIONS_DEFAULT=WEBGL
WEBGL_DESC=	Enable Web GL support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWEBGL}
USE_GL=		gl
CONFIGURE_ARGS+=--enable-webgl
.else
CONFIGURE_ARGS+=--disable-webgl
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${ARCH} == powerpc64
CFLAGS+=	-mminimal-toc
.endif

CCISCLANG!=     ${CC} --version

.if !empty(CCISCLANG:M*clang*)
CPPFLAGS+=	-Wno-c++11-extensions
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+=	p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/Source/WebCore/plugins/PluginDatabase.cpp
	@${FIND} ${WRKSRC} -name GNUmakefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|' \
		${WRKSRC}/Source/WebCore/dom/make_names.pl \
		${WRKSRC}/Source/WebCore/css/make-css-file-arrays.pl \
		${WRKSRC}/Source/WebCore/bindings/scripts/IDLParser.pm
	@${REINPLACE_CMD} -e 's|"gperf|"${LOCALBASE}/bin/gperf|g' \
		${WRKSRC}/Source/WebCore/css/makevalues.pl \
		${WRKSRC}/Source/WebCore/css/makeprop.pl \
		${WRKSRC}/Source/WebCore/make-hash-tools.pl

post-install:
# Add work around for epiphany 2.x gobject-introspection build.
	${LN} -sf ${PREFIX}/libdata/pkgconfig/webkit-1.0.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/webkitgtk-1.0.pc

.include <bsd.port.post.mk>
