PORTNAME=	libmediainfo
PORTVERSION=	25.07
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/binary/mediainfo/${PORTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MediaInfo library
WWW=		https://mediaarea.net/en/MediaInfo \
		https://github.com/MediaArea/MediaInfoLib

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../License.html

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libtinyxml2.so:textproc/tinyxml2 \
		libzen.so:multimedia/libzen

USES=		compiler:c++11-lang dos2unix libtool localbase pathfix pkgconfig tar:xz

CONFIGURE_ARGS=	--enable-shared --enable-static --with-libcurl=${LOCALBASE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PATHFIX_MAKEFILEIN+=	configure
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource/MediaInfoLib/Project/GNU/Library

DOS2UNIX_FILES=	../../../Source/MediaInfo/Audio/File_Usac.cpp \
		../../../Source/MediaInfo/Audio/File_Usac.h

.include <bsd.port.mk>
