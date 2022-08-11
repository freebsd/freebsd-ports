PORTNAME=	libharu
DISTVERSIONPREFIX=	RELEASE_
DISTVERSION=	2_3_0
PORTREVISION=	2
CATEGORIES=	print
DIST_SUBDIR=	${PORTNAME}

# Kitware (vtk) calls this version 2.4.0 with the addition of
PATCHFILES=	157.diff:-p1 187.diff:-p1
PATCH_SITES=	https://github.com/libharu/libharu/pull/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Haru Free PDF Library

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png

OPTIONS_DEFINE=	EXAMPLES

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes

SOVERSION=	2
PLIST_SUB+=	SOVERSION=${SOVERSION}
PORTEXAMPLES=	*

EXAMPLES_CMAKE_ON=	-DLIBHPDF_EXAMPLES:BOOL=ON  \
			-DEXAMPLESDIR:STRING=share/examples/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e 's|RC2|dev|;s|3|4|' ${WRKSRC}/include/hpdf_version.h

post-install:
	${LN} -s libhpdf.so ${STAGEDIR}${PREFIX}/lib/libhpdf.so.${SOVERSION}

.include <bsd.port.mk>
