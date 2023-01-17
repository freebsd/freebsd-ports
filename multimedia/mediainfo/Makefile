PORTNAME=	mediainfo
DISTVERSION=	22.12
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/source/${PORTNAME}/${DISTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides technical and tag information for video and audio files
WWW=		https://mediaarea.net/en/MediaInfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../License.html

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo \
		libzen.so:multimedia/libzen

USES=		autoreconf compiler:c++11-lang cpe dos2unix libtool pathfix \
		pkgconfig tar:xz

GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes
CPE_VENDOR=	mediaarea
DOS2UNIX_GLOB=	*.c *.cpp *.h
DOS2UNIX_WRKSRC=	${WRKDIR}

PLIST_FILES=	bin/mediainfo
WRKSRC=		${WRKDIR}/MediaInfo/Project/GNU/CLI

.include <bsd.port.mk>
