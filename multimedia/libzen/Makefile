PORTNAME=	libzen
PORTVERSION=	0.4.41.${MEDIAINFO_VERSION}
PORTEPOCH=	3
CATEGORIES=	multimedia
MASTER_SITES=	https://mediaarea.net/download/binary/mediainfo/${MEDIAINFO_VERSION}/ \
		LOCAL/sunpoet
DISTNAME=	MediaInfo_CLI_${MEDIAINFO_VERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ZenLib used by MediaInfo and its library
WWW=		https://mediaarea.net/en/MediaInfo \
		https://github.com/MediaArea/ZenLib

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/../../../License.txt

USES=		compiler:c++11-lang dos2unix libtool pathfix tar:xz

CONFIGURE_ARGS=	--enable-shared --enable-static
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource/ZenLib/Project/GNU/Library

MEDIAINFO_VERSION=	25.07

.include <bsd.port.mk>
