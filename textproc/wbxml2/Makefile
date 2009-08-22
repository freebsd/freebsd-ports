# New ports collection makefile for:	wbxml
# Date created:			Nov 04, 2005
# Whom:				Clemens Zauner <czauner+ports@onlineloop.com>
#
# $FreeBSD$
#

PORTNAME=	wbxml2
PORTVERSION=	0.10.6
CATEGORIES=	textproc devel
MASTER_SITES=	SF/libwbxml/libwbxml/${PORTVERSION}
DISTNAME=	libwbxml-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library & tools for converting wbxml<->xml

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_BZIP2=	YES
USE_CMAKE=	YES

WRKSRC=		${WRKDIR}/libwbxml-${PORTVERSION}/build
CMAKE_SOURCE_PATH=..
PATCH_WRKSRC=	${WRKDIR}/libwbxml-${PORTVERSION}
.if defined(NOPORTDOCS)
EXTRA_PATCHES=	${FILESDIR}/noportdocs-CMakeLists.txt.diff
.endif

pre-patch:
	@cd ${PATCH_WRKSRC}

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
