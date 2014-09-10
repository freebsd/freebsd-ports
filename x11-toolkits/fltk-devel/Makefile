# Created by: gahr
# $FreeBSD$

PORTNAME=	fltk
DISTVERSION=	1.3.x-r${SNAPSHOT_VERS}
PORTREVISION=	1
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
EXAMPLES_CMAKE_OFF=	-DOPTION_BUILD_EXAMPLES:BOOL=OFF

USE_XORG=	xft
USE_GL=		glu
USE_LDCONFIG=	${PREFIX}/lib/fltk-devel
USES+=		cmake:outsource
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DOPTION_BUILD_SHARED_LIBS:BOOL=ON \
    		-DOPTION_PREFIX_BIN:PATH=${PREFIX}/bin/fltk-devel \
		-DOPTION_PREFIX_DATA:PATH=${PREFIX}/share/fltk-devel \
		-DOPTION_PREFIX_DOC:PATH=${PREFIX}/share/examples/fltk-devel \
		-DOPTION_PREFIX_INCLUDE:PATH=${PREFIX}/include/fltk-devel \
		-DOPTION_PREFIX_LIB:PATH=${PREFIX}/lib/fltk-devel


SNAPSHOT_VERS=	10272
PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

PORTSCOUT=	limit:1.3.*

post-install:
	${LN} -sf fltk-devel/libfltk.so ${STAGEDIR}${PREFIX}/lib/libfltk-devel.so

.include <bsd.port.mk>
