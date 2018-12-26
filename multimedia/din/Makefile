# $FreeBSD$

PORTNAME=	din
PORTVERSION=	38a
CATEGORIES=	multimedia
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	DIN Is Noise is an open source, cross-platform sound \
		synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libasound.so:audio/alsa-lib \
		libjack.so:audio/jack \
		libtcl${TCL_SHLIB_VER}.so:lang/tcl${TCL_SHLIB_VER} \
		libSDL.so:devel/sdl12 \
		libGL.so:graphics/mesa-libs

USES=		autoreconf tcl:86+ gnome

GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	JACK ALSA
OPTIONS_DEFAULT=	JACK

JACK_DESC=	Uses JACK sound server
ALSA_DESC=	Uses ALSA sound server

ALSA_CXXFLAGS+=	-D__LINUX_ALSA__
JACK_CXXFLAGS+=	-D__UNIX_JACK__

CXXFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/tcl${TCL_VER}
LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -lthr

.include <bsd.port.mk>
