# Created by: freebsd-ports@evilcode.net
# $FreeBSD$

PORTNAME=	mediainfo
PORTVERSION=	0.7.52
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/binary/${PORTNAME}/${PORTVERSION}
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Supplies technical and tag information about a video or audio file

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/MediaInfo/License.html

USES=		libtool tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_SCRIPT=	CLI_Compile.sh
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource

PLIST_FILES=	bin/mediainfo \
		lib/libmediainfo.a \
		lib/libmediainfo.so \
		lib/libmediainfo.so.0 \
		lib/libmediainfo.so.0.0.0 \
		lib/libzen.a \
		lib/libzen.so \
		lib/libzen.so.0 \
		lib/libzen.so.0.0.0

SUBDIRS=	ZenLib/Project/GNU/Library \
		MediaInfoLib/Project/GNU/Library \
		MediaInfo/Project/GNU/CLI

do-install:
.for d in ${SUBDIRS}
	@(cd ${WRKSRC}/$d && ${MAKE_CMD} ${MAKE_ARGS} install)
.endfor

.include <bsd.port.mk>
