PORTNAME=	libzen
DISTVERSION=	0.4.41.25.03
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	multimedia

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ZenLib used by MediaInfo and its library
WWW=		https://mediaarea.net/en/MediaInfo \
		https://github.com/MediaArea/ZenLib

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/../../License.txt

USES=		cmake compiler:c++11-lang dos2unix pathfix pkgconfig tar:xz
DOS2UNIX_GLOB=	*.c *.cmake.in *.cpp *.h *.pc.in *.txt
DOS2UNIX_WRKSRC=${WRKDIR}
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MediaArea
GH_PROJECT=	ZenLib
GH_TAGNAME=	16e8ba0

WRKSRC_SUBDIR=	Project/CMake

post-patch:
	@${REINPLACE_CMD} -e '/^Libs_Static/d' ${PATCH_WRKSRC}/libzen.pc.in

.include <bsd.port.mk>
