# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloop-utils
PORTVERSION=	${CLOOP_VERSION}.${CLOOP_REVISION}
CATEGORIES=	sysutils
MASTER_SITES=	http://debian-knoppix.alioth.debian.org/sources/
DISTNAME=	cloop_${CLOOP_VERSION}-${CLOOP_REVISION}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Compressed loop FS utils

BROKEN=		unfetchable

USES=		gmake

WRKSRC=		${WRKDIR}/cloop-${CLOOP_VERSION}
MAKE_ENV=	APPSONLY=yes
PLIST_FILES=	bin/create_compressed_fs bin/extract_compressed_fs

PORTDOCS=	README

CLOOP_VERSION=	2.01
CLOOP_REVISION=	2

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS:=/CFLAGS?=/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/create_compressed_fs ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/extract_compressed_fs ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
