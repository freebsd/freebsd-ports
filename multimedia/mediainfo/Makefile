# New ports collection makefile for:	mediainfo
# Date created:		24 April 2008
# Whom:			freebsd-ports@evilcode.net
#
# $FreeBSD$
#

PORTNAME=		mediainfo
PORTVERSION=		0.7.33
DISTVERSIONSUFFIX=	_AllInclusive
CATEGORIES=		multimedia
MASTER_SITES=		SF/${PORTNAME}/source/${PORTNAME}/${PORTVERSION}
DISTNAME=		mediainfo_${PORTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=		.7z

MAINTAINER=	freebsd-ports@evilcode.net
COMMENT=	Supplies technical and tag information about a video or audio file

EXTRACT_DEPENDS=	p7zip>=0:${PORTSDIR}/archivers/p7zip

PLIST_FILES=	bin/mediainfo

EXTRACT_CMD=	7z
USE_AUTOTOOLS=	autotools:build

WRKSRC=		${WRKDIR}/MediaInfo${DISTVERSIONSUFFIX}

do-extract:
	@(${MKDIR} ${WRKSRC} && ${EXTRACT_CMD} x -o${WRKSRC} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})

pre-build:
	@(cd ${WRKSRC} && ${CP} ./MediaInfo/Project/GNU/CLI/AddThisToRoot_CLI_compile.sh ./CLI_Compile.sh)

do-build:
	@(cd ${WRKSRC}/ZenLib/Project/GNU/Library/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/MediaInfoLib/Project/GNU/Library/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/MediaInfo/Project/GNU/CLI/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/ && ${SH} ./CLI_Compile.sh --prefix=${PREFIX})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MediaInfo/Project/GNU/CLI/mediainfo ${PREFIX}/bin

.include <bsd.port.mk>
