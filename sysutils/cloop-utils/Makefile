# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

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
PLIST_FILES=	bin/create_compressed_fs bin/extract_compressed_fs

.ifndef NOPORTDOCS
PORTDOCS=	README
.endif

CLOOP_VERSION=	2.01
CLOOP_REVISION=	2

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS:=/CFLAGS?=/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/create_compressed_fs ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/extract_compressed_fs ${PREFIX}/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
