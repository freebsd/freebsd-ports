# New ports collection makefile for:	cloop-utils
# Date created:				19 Jan 2004
# Whom:					Max Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cloop-utils
PORTVERSION=	${CLOOP_VERSION}.${CLOOP_REVISION}
CATEGORIES=	sysutils
MASTER_SITES=	http://debian-knoppix.alioth.debian.org/sources/
DISTNAME=	cloop_${CLOOP_VERSION}-${CLOOP_REVISION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Compressed loop FS utils

WRKSRC=		${WRKDIR}/cloop-${CLOOP_VERSION}
USE_GMAKE=	yes
MAKE_ENV=	APPSONLY=yes
PORTDOCS=	README
PLIST_FILES=	bin/create_compressed_fs bin/extract_compressed_fs

CLOOP_VERSION=	2.01
CLOOP_REVISION=	2

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS:=/CFLAGS?=/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/create_compressed_fs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/extract_compressed_fs ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

.include <bsd.port.mk>
