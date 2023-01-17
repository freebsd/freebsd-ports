PORTNAME=	libmediainfo
DISTVERSION=	22.12
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/source/${PORTNAME}/${DISTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MediaInfo library
WWW=		https://mediaarea.net/en/MediaInfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../License.html

LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2 \
		libzen.so:multimedia/libzen

USES=		cmake compiler:c++11-lang dos2unix localbase:ldflags pathfix \
		pkgconfig tar:xz
USE_LDCONFIG=	yes
DOS2UNIX_GLOB=	*.c *.cmake.in *.cpp *.h *.pc.in *.txt
DOS2UNIX_WRKSRC=	${WRKDIR}

CXXFLAGS+=	-D_POSIX_PRIORITY_SCHEDULING

WRKSRC=		${WRKDIR}/MediaInfoLib/Project/CMake
PLIST_SUB=	DISTVERSION=${DISTVERSION:S|.||g}

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	CURL

CURL_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_CURL:BOOL=True
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

post-patch:
	@${REINPLACE_CMD} -e '/^Libs_Static/d' ${PATCH_WRKSRC}/libmediainfo.pc.in

.include <bsd.port.mk>
