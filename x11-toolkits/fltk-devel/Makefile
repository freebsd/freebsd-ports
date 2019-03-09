# Created by: gahr
# $FreeBSD$

PORTNAME=	fltk
DISTVERSION=	1.3.x-r${SNAPSHOT_VERS}
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://fltk.org/pub/${PORTNAME}/snapshots/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform C++ graphical user interface toolkit

LICENSE=	LGPL20

LIB_DEPENDS=	libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cmake gl jpeg localbase:ldflags
USE_CXXSTD=	c++98
USE_XORG=	xft
USE_GL=		glu
USE_LDCONFIG=	${PREFIX}/lib/fltk-devel
CMAKE_ARGS=	-DOPTION_BUILD_SHARED_LIBS:BOOL=ON \
		-DPREFIX_BIN:PATH=${PREFIX}/bin/fltk-devel \
		-DPREFIX_DATA:PATH=${PREFIX}/share/fltk-devel \
		-DPREFIX_DOC:PATH=${PREFIX}/share/examples/fltk-devel \
		-DPREFIX_INCLUDE:PATH=${PREFIX}/include/fltk-devel \
		-DPREFIX_LIB:PATH=${PREFIX}/lib/fltk-devel

DEPRECATED=	Older than x11-toolkits/fltk -- there is no point in having old snapshots
EXPIRATION_DATE=	2019-03-31

SNAPSHOT_VERS=	10370
PORTEXAMPLES=	*
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

PORTSCOUT=	limit:1.3.*

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_CMAKE_OFF=	-DOPTION_BUILD_EXAMPLES:BOOL=OFF

post-install:
	${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/fltk-config ${STAGEDIR}${PREFIX}/bin/fltk-devel
	${LN} -sf fltk-devel/libfltk.so ${STAGEDIR}${PREFIX}/lib/libfltk-devel.so

.include <bsd.port.mk>
