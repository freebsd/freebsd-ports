# Created by: gahr
# $FreeBSD$

PORTNAME=	fltk
DISTVERSION=	1.3.x-r${SNAPSHOT_VERS}
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fltk.org/pub/${PORTNAME}/snapshots/
PKGNAMESUFFIX=	-devel

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LICENSE=	LGPL20

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	EXAMPLES

USE_XORG=	xft
USE_GL=		glu
USE_LDCONFIG=	${PREFIX}/lib/fltk-devel
USES+=		cmake:outsource
CMAKE_ARGS+=	-DOPTION_BUILD_SHARED_LIBS:BOOL=ON \
    		-DOPTION_PREFIX_BIN:PATH=${PREFIX}/bin/fltk-devel \
		-DOPTION_PREFIX_DATA:PATH=${PREFIX}/share/fltk-devel \
		-DOPTION_PREFIX_DOC:PATH=${PREFIX}/share/examples/fltk-devel \
		-DOPTION_PREFIX_INCLUDE:PATH=${PREFIX}/include/fltk-devel \
		-DOPTION_PREFIX_LIB:PATH=${PREFIX}/lib/fltk-devel

SNAPSHOT_VERS=	10122
PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DOPTION_BUILD_EXAMPLES:BOOL=ON
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CMAKE_ARGS+=	-DOPTION_BUILD_EXAMPLES:BOOL=OFF
.endif

post-install:
	${LN} -sf fltk-devel/libfltk.so ${STAGEDIR}${PREFIX}/lib/libfltk-devel.so

.include <bsd.port.mk>
