PORTNAME=	libcec
PORTVERSION=	7.1.1
DISTVERSIONPREFIX=	libcec-
CATEGORIES=	multimedia

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to control Pulse-Eight's HDMI-CEC adapter
WWW=		https://libcec.pulse-eight.com/ \
		https://github.com/Pulse-Eight/libcec

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libp8-platform.so:devel/p8-platform

USES=		alias cmake compiler:c++11-lib pathfix pkgconfig shebangfix

CMAKE_ARGS=	-DCMAKE_REQUIRED_INCLUDES=${LOCALBASE}/include \
		-DCMAKE_REQUIRED_FLAGS=-L${LOCALBASE}/lib \
		-DGIT_REVISION=libcec-${PORTVERSION}
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	Pulse-Eight

SHEBANG_FILES=	src/pyCecClient/pyCecClient.py

OPTIONS_DEFINE=	PYTHON X11
OPTIONS_DEFAULT=PYTHON X11
OPTIONS_EXCLUDE_armv6=	X11
OPTIONS_EXCLUDE_armv7=	X11
OPTIONS_SUB=	yes
PYTHON_DESC=	Build python wrapper

PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_CMAKE_BOOL_OFF=	SKIP_PYTHON_WRAPPER
PYTHON_USES=		python:build
X11_USE_OFF=		XORG=x11,xorgproto,xrandr
X11_USES_OFF=		xorg

post-patch-PYTHON-off:
	@${REINPLACE_CMD} '/pyCecClient/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
