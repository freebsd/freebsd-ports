PORTNAME=	libmediainfo
DISTVERSION=	25.03
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/source/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MediaInfo library
WWW=		https://mediaarea.net/en/MediaInfo \
		https://github.com/MediaArea/MediaInfoLib

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../License.html

LIB_DEPENDS=	libtinyxml2.so:textproc/tinyxml2 \
		libzen.so:multimedia/libzen

USES=		cmake compiler:c++11-lang dos2unix localbase:ldflags pathfix \
		pkgconfig tar:xz
DOS2UNIX_GLOB=	*.c *.cmake.in *.cpp *.h *.pc.in *.txt
DOS2UNIX_WRKSRC=${WRKDIR}
USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS=	--exclude MediaInfoLib/Source/ThirdParty/tinyxml2
WRKSRC=		${WRKDIR}/MediaInfoLib/Project/CMake

PLIST_SUB=	DISTVERSION=${DISTVERSION:S/.//}

CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	CURL
OPTIONS_DEFAULT=CURL

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_CURL

post-patch:
	@${REINPLACE_CMD} -e '/^Libs_Static/d' ${PATCH_WRKSRC}/libmediainfo.pc.in
	${RM} -r ${STAGEDIR}${PREFIX}/include/MediaInfoDLL/

.include <bsd.port.mk>
