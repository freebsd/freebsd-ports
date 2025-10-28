PKGNAMESUFFIX=	-gui
COMMENT=	subtitle extractor (GUI)

RUN_DEPENDS=	ccextractor:multimedia/ccextractor
LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		gl xorg
USE_GL=		glew gl glu opengl
USE_XORG=	x11 xinerama xcursor xi xrandr xxf86vm

# always show the OCR menu option
CFLAGS=		-DENABLE_OCR
ALL_TARGET=	ccextractorGUI

CONFIGURE_ARGS=	--with-gui --without-rust
CFLAGS+=	-DNK_INCLUDE_FIXED_TYPES

MASTERDIR=	${.CURDIR}/../ccextractor

.include	"${MASTERDIR}/Makefile.master"
