# $FreeBSD$

PORTNAME=	webkit
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt WebKit implementation

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libicui18n.so:devel/icu \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex

BROKEN_sparc64=	cannot build: uses i386 assembler

USE_GL=		gl
USE_GNOME=	libxml2 libxslt
USE_PERL5=	build
USE_QT5=	core gui network opengl printsupport qml quick sql \
		widgets buildtools_build
QT_DIST=	${PORTNAME}
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_XORG=	x11 xcomposite xrender
USES=		bison gperf jpeg perl5 pkgconfig python:build qmake:outsource \
		sqlite
# Use flex(1) from ports.
MAKE_ENV=	PATH="${LOCALBASE}/bin:${PATH}"
# "all" builds many more targets. The default one is called "first" in
# QtWebKit, and is invoked by default when make is called without arguments.
ALL_TARGET=	first
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

OPTIONS_DEFINE=	GSTREAMER
OPTIONS_DEFAULT=GSTREAMER

GSTREAMER_USE=	GNOME=glib20 GSTREAMER1=yes

.include <bsd.port.pre.mk>

# Base ld(1) segfaults on PowerPC (inherited from Qt 4):
# http://bugs.freebsd.org/173042
.if ${ARCH} == "powerpc"
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:devel/binutils
.endif

post-patch:
	${REINPLACE_CMD} -e 's,python,${PYTHON_VERSION},g' \
		-e 's,$$$${PYTHON},${PYTHON_VERSION},g' \
		${WRKSRC}/Source/WebCore/DerivedSources.make \
		${WRKSRC}/Source/WebCore/DerivedSources.pri \
		${WRKSRC}/Source/WebKit2/DerivedSources.make \
		${WRKSRC}/Source/WebKit2/DerivedSources.pri \
		${WRKSRC}/Source/JavaScriptCore/DerivedSources.make \
		${WRKSRC}/Source/JavaScriptCore/DerivedSources.pri \
		${WRKSRC}/Tools/qmake/mkspecs/features/configure.prf

pre-configure:
	@${REINPLACE_CMD} -Ee 's|linux-?\*|unix|g' \
		${WRKSRC}/Source/JavaScriptCore/DerivedSources.pri \
		${WRKSRC}/Source/JavaScriptCore/JavaScriptCore.pri \
		${WRKSRC}/Source/JavaScriptCore/Target.pri \
		${WRKSRC}/Source/WebCore/WebCore.pri \
		${WRKSRC}/Tools/qmake/mkspecs/features/features.prf
.if ! ${PORT_OPTIONS:MGSTREAMER}
	@${REINPLACE_CMD} -e 's|packagesExist.*gstreamer.*|false {|' \
		${WRKSRC}/Tools/qmake/mkspecs/features/features.prf
.endif

.include <bsd.port.post.mk>
