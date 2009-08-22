# New ports collection makefile for:	mediainfo
# Date created:		24 April 2008
# Whom:			freebsd-ports@evilcode.net
#
# $FreeBSD$
#

PORTNAME=		mediainfo
PORTVERSION=		0.7.7.8
DISTVERSIONSUFFIX=	_CLI_GNU_FromSource
CATEGORIES=		multimedia
MASTER_SITES=		SF/${PORTNAME}/MediaInfo%20-%20Command%20line/${PORTVERSION}
DISTNAME=		MediaInfo_${PORTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	freebsd-ports@evilcode.net
COMMENT=	Supplies technical and tag information about a video or audio file

PLIST_FILES=	bin/mediainfo

USE_BZIP2=	yes
USE_DOS2UNIX=	int128s.cpp int128u.cpp

WRKSRC=		${WRKDIR}/MediaInfo${DISTVERSIONSUFFIX}

do-build:
	@(cd ${WRKSRC}/ && ${SH} ./CLI_Compile.sh --prefix=${PREFIX})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MediaInfo/Project/GNU/CLI/mediainfo ${PREFIX}/bin

.include <bsd.port.mk>
