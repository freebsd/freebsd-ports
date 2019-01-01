# Created by: freebsd-ports@evilcode.net
# $FreeBSD$

PORTNAME=	mediainfo
PORTVERSION=	18.12
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/binary/${PORTNAME}/${PORTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides technical and tag information for video and audio files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../License.html

LIB_DEPENDS=	libmediainfo.so:multimedia/libmediainfo \
		libzen.so:multimedia/libzen

USES=		compiler:c++11-lang libtool pathfix pkgconfig tar:xz

GNU_CONFIGURE=	yes
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_FILES=	bin/mediainfo
WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource/MediaInfo/Project/GNU/CLI

.include <bsd.port.mk>
