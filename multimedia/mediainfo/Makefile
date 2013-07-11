# Created by: freebsd-ports@evilcode.net
# $FreeBSD$

PORTNAME=	mediainfo
PORTVERSION=	0.7.52
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/binary/${PORTNAME}/${PORTVERSION}
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Supplies technical and tag information about a video or audio file

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/MediaInfo/License.html

USE_AUTOTOOLS=	aclocal:env automake:env autoconf:env libtool:env
USE_BZIP2=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource

PLIST_FILES=	bin/mediainfo \
		lib/libmediainfo.so \
		lib/libmediainfo.so.0 \
		lib/libzen.so \
		lib/libzen.so.0

do-build:
	@(cd ${WRKSRC}/ZenLib/Project/GNU/Library/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/MediaInfoLib/Project/GNU/Library/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/MediaInfo/Project/GNU/CLI/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/ && ${SH} ./CLI_Compile.sh --prefix=${PREFIX} --enable-shared)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MediaInfo/Project/GNU/CLI/.libs/mediainfo ${PREFIX}/bin/
.for library in MediaInfo Zen
	${INSTALL_LIB} ${WRKSRC}/${library}Lib/Project/GNU/Library/.libs/lib${library:L}.so.0 ${PREFIX}/lib/
	${LN} -fs lib${library:L}.so.0 ${PREFIX}/lib/lib${library:L}.so
.endfor

.include <bsd.port.mk>
