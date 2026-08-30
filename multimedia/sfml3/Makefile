PORTNAME=	SFML
DISTVERSION=	3.0.0
CATEGORIES=	multimedia audio devel games

MAINTAINER=	agh@riseup.net
COMMENT=	Simple and Fast Multimedia Library
WWW=		https://github.com/SFML/SFML \
		https://www.sfml-dev.org/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/license.md

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS SFML_USE_SYSTEM_DEPS

CONFLICTS=	sfml2

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

PLIST_SUB=	SO_RELEASE=${_SO_RELEASE} \
		SO_VERSION=${_SO_VERSION}
PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS DOXYGEN EXAMPLES
OPTIONS_DEFAULT=	${OPTIONS_GROUP_MODULES}
OPTIONS_GROUP=		MODULES
OPTIONS_GROUP_MODULES=	AUDIO GRAPHICS NETWORK WINDOW
OPTIONS_SUB=		yes

AUDIO_DESC=	SFML Audio module
GRAPHICS_DESC=	SFML Graphics module
MODULES_DESC=	SFML modules
NETWORK_DESC=	SFML Network module
WINDOW_DESC=	SFML Window module

AUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/miniaudio/miniaudio.h:audio/miniaudio
AUDIO_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
AUDIO_CMAKE_BOOL=	SFML_BUILD_AUDIO
DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_BROKEN=		option DOXYGEN breaks the build failing to generate doxygen file SFML.tag
DOXYGEN_CMAKE_BOOL=	SFML_BUILD_DOC
EXAMPLES_CMAKE_BOOL=	SFML_BUILD_EXAMPLES
GRAPHICS_IMPLIES=	WINDOW
GRAPHICS_LIB_DEPENDS=	libfreetype.so:print/freetype2
GRAPHICS_CMAKE_BOOL=	SFML_BUILD_GRAPHICS
NETWORK_CMAKE_BOOL=	SFML_BUILD_NETWORK
WINDOW_USES=		gl xorg
WINDOW_USE=		GL=gl \
			XORG=x11,xcursor,xext,xfixes,xi,xrandr,xrender
WINDOW_CMAKE_BOOL=	SFML_BUILD_WINDOW

_DIST_EXCLUDES=		.clang-format .clang-tidy .editorconfig .gitattributes \
			.github .gitignore changelog.md CONTRIBUTING.md \
			examples/android examples/cocoa examples/win32 \
			migration.md readme.md
_EXAMPLES_ASSETS=	-type f -not -name '*.bak' -not -name '*.cpp' -not \
			-name '*.h' -not -name '*.hpp' -not -name '*.orig' -not \
			-name CMakeLists.txt
_EXAMPLES_PROGRAM=	-depth 1 -type f -and -not -type d -and -perm -o=+x
_EXAMPLES_SOURCE=	"-not -name *.bak -not -name *.orig -not -regex .*assets.* -not -name asset_licenses.md -not -name CMakeLists.txt -not -regex .*resources.*"
_SO_RELEASE=		${DISTVERSION:R}
_SO_VERSION=		${DISTVERSION}

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/examples/event_handling/EventHandling.cpp \
		${WRKSRC}/examples/island/Island.cpp \
		${WRKSRC}/examples/joystick/Joystick.cpp \
		${WRKSRC}/examples/keyboard/Keyboard.cpp \
		${WRKSRC}/examples/opengl/OpenGL.cpp \
		${WRKSRC}/examples/raw_input/RawInput.cpp \
		${WRKSRC}/examples/shader/Shader.cpp \
		${WRKSRC}/examples/sound_effects/SoundEffects.cpp \
		${WRKSRC}/examples/sound/Sound.cpp \
		${WRKSRC}/examples/tennis/Tennis.cpp \
		${WRKSRC}/examples/vulkan/Vulkan.cpp

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${FIND} ${WRKSRC}/examples ${_EXAMPLES_ASSETS} -execdir ${INSTALL_DATA} \
		{} ${STAGEDIR}${DATADIR}/{} \;
	(cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} ${_EXAMPLES_SOURCE})
	${FIND} ${BUILD_WRKSRC}/bin ${_EXAMPLES_PROGRAM} -execdir ${INSTALL_PROGRAM} \
		{} ${STAGEDIR}${PREFIX}/bin/${PORTNAME:tl}-example-{} \
		\;

.include <bsd.port.mk>
