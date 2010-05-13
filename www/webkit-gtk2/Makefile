# New ports collection makefile for:	webkit
# Date created:		2007-10-21
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/webkit-gtk2/Makefile,v 1.60 2010/04/05 17:39:13 kwm Exp $
#

PORTNAME=	webkit
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	http://webkitgtk.org/
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An opensource browser engine

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection \
		${LOCALBASE}/share/gir-1.0/Soup-2.4.gir:${PORTSDIR}/devel/gir-repository-libsoup
LIB_DEPENDS=	enchant.1:${PORTSDIR}/textproc/enchant \
		curl.6:${PORTSDIR}/ftp/curl \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		soup-2.4.1:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/Soup-2.4.gir:${PORTSDIR}/devel/gir-repository-libsoup

WANT_GSTREAMER=	yes
MAKE_JOBS_SAFE=	yes
USE_XORG=	xt
USE_BISON=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk20 libxslt ltverhack:13
USE_PERL5=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		ac_cv_path_FLEX="${LOCALBASE}/bin/flex" \
		ac_cv_path_DOLT_BASH=""
CONFIGURE_ARGS=	--enable-icon-database \
		--enable-svg \
		--enable-svg-fonts \
		--enable-introspection
MAKEFILE=	GNUmakefile

BROWSER_PLUGINS_DIR?=	${LOCALBASE}/lib/browser_plugins/symlinks/webkit-gtk2
#_BROWSER_PLUGINS_DIR=	${BROWSER_PLUGINS_DIR:S|^/|"|:S|/|", "|g}",

OPTIONS=	VIDEO "Enable video support" on \
		DEBUG "Build with debug support" off \
		STATIC "Enable building static library" off

.include <bsd.port.pre.mk>

.if exists (${LOCALBASE}/lib/libicutu.so.43)
LIB_DEPENDS+=	icutu.43:${PORTSDIR}/devel/icu4
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-WebCore_platform_text_TextBreakIterator.h
.else
LIB_DEPENDS+=	icutu.38:${PORTSDIR}/devel/icu
.endif

.if defined(WITH_VIDEO)
USE_GSTREAMER+=	yes
CONFIGURE_ARGS+=--enable-video
.else
CONFIGURE_ARGS+=--disable-video
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if defined(WITH_STATIC)
CONFIGURE_ARGS+=--enable-static
PLIST_SUB+=	STATIC=""
.else
PLIST_SUB+=	STATIC="@comment "
.endif

.if ${OSVERSION} < 700000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-JavaScriptCore_yarr_RegexJIT.h \
		${FILESDIR}/extra-patch-JavaScriptCore_assembler_MacroAssemblerCodeRef.h
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%BROWSER_PLUGINS_DIR%%|${BROWSER_PLUGINS_DIR}|' \
		${WRKSRC}/WebCore/plugins/PluginDatabase.cpp
	@${FIND} ${WRKSRC} -name GNUmakefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'
.if !defined(WITH_STATIC)
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|' \
		${WRKDIR}/gnome-libtool
.endif
	@${REINPLACE_CMD} -e 's|/usr/bin/gcc|${CC}|' \
		${WRKSRC}/WebCore/dom/make_names.pl \
		${WRKSRC}/WebCore/css/make-css-file-arrays.pl \
		${WRKSRC}/WebCore/bindings/scripts/IDLParser.pm

.include <bsd.port.post.mk>
