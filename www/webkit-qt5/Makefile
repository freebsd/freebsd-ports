# $FreeBSD$

PORTNAME=	webkit
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	www
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt WebKit implementation

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libicui18n.so:${PORTSDIR}/devel/icu \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libwebp.so:${PORTSDIR}/graphics/webp
BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_GL=		gl
USE_GNOME=	libxml2 libxslt
USE_PERL5=	build
USE_QT5=	core gui network opengl printsupport qml quick sql \
		testlib widgets buildtools_build
QT_DIST=	${PORTNAME}
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_SQLITE=	3
USE_XORG=	x11 xcomposite xrender
USES=		bison gmake gperf perl5 pkgconfig python:build qmake:outsource
# Keep make(1) from descending into obj/ subdirectories during tests.
CONFIGURE_ENV=	MAKEOBJDIR=.
# Use flex(1) from ports.
MAKE_ENV=	PATH="${LOCALBASE}/bin:${PATH}"
# Probably required.
ALL_TARGET=	first
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

OPTIONS_DEFINE=	GSTREAMER
OPTIONS_DEFAULT=GSTREAMER

GSTREAMER_USE=	GNOME=glib20 GSTREAMER=yes

.include <bsd.port.pre.mk>

# Base ld(1) segfaults on PowerPC (inherited from Qt 4):
# http://bugs.freebsd.org/173042
.if ${ARCH} == "powerpc"
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:${PORTSDIR}/devel/binutils
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
# Write a clean installation procedure to avoid the installation of
# the file during the build stage.
	@${REINPLACE_CMD} -e 's|\[QT_INSTALL_PLUGINS]|{ROOT_BUILD_DIR}/plugins|' \
		${WRKSRC}/Source/WebKit/qt/examples/platformplugin/platformplugin.pro
	@${ECHO_CMD} "target.path = ${PREFIX}/${QT_PLUGINDIR_REL}/webkit" \
		>> ${WRKSRC}/Source/WebKit/qt/examples/platformplugin/platformplugin.pro
	@${ECHO_CMD} "INSTALLS += target" \
		>> ${WRKSRC}/Source/WebKit/qt/examples/platformplugin/platformplugin.pro
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
