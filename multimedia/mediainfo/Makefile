# New ports collection makefile for:	mediainfo
# Date created:		24 April 2008
# Whom:			freebsd-ports@evilcode.net
#
# $FreeBSD$
#

PORTNAME=	mediainfo
PORTVERSION=	0.7.48
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/binary/${PORTNAME}/${PORTVERSION}
DISTNAME=	MediaInfo_CLI_${PORTVERSION}_GNU_FromSource

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supplies technical and tag information about a video or audio file

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/MediaInfo/License.html

USE_AUTOTOOLS=	aclocal:env automake:env autoconf:env libtool:env
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/MediaInfo_CLI_GNU_FromSource

PLIST_FILES=	bin/mediainfo

do-build:
	@(cd ${WRKSRC}/ZenLib/Project/GNU/Library/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/MediaInfoLib/Project/GNU/Library/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/MediaInfo/Project/GNU/CLI/ && ${SH} ./autogen)
	@(cd ${WRKSRC}/ && ${SH} ./CLI_Compile.sh --prefix=${PREFIX})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MediaInfo/Project/GNU/CLI/mediainfo ${PREFIX}/bin/

.include <bsd.port.mk>
