# Created by: freebsd-ports@evilcode.net
# $FreeBSD$

PORTNAME=	mediainfo
PORTVERSION=	0.7.78
CATEGORIES=	multimedia
MASTER_SITES=	http://mediaarea.net/download/binary/${PORTNAME}/${PORTVERSION}/ \
		LOCAL/sunpoet
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides technical and tag information for video and audio files

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../License.html

LIB_DEPENDS=	libmediainfo.so:${PORTSDIR}/multimedia/libmediainfo \
		libzen.so:${PORTSDIR}/multimedia/libzen

CONFIGURE_ARGS=	--enable-shared
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool pathfix pkgconfig tar:bzip2

PLIST_FILES=	bin/mediainfo
WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource/MediaInfo/Project/GNU/CLI

.include <bsd.port.mk>
