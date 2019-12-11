# $FreeBSD$

PORTNAME=	din
PORTVERSION=	43.0.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Open source, cross-platform sound synthesizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libboost_system.so:devel/boost-libs \
		libjack.so:audio/jack

USES=		autoreconf gl gnome sdl tcl:86+ xorg
USE_GL=		gl
USE_SDL=	sdl

GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	ALSA JACK
OPTIONS_DEFAULT=	JACK

JACK_DESC=	Uses JACK sound server
ALSA_DESC=	Uses ALSA sound server

ALSA_CXXFLAGS+=	-D__LINUX_ALSA__
JACK_CXXFLAGS+=	-D__UNIX_JACK__

CXXFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/tcl${TCL_VER}
LIBS+=		-L${LOCALBASE}/lib -ltcl${TCL_SHLIB_VER} -lthr -ljack

.include <bsd.port.mk>
