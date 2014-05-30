# Created by: Tim Welch <ports@thepentagon.org>
# $FreeBSD$

PORTNAME=	dvdimagecmp
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	SUNSITE
MASTER_SITE_SUBDIR=	apps/video
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@thepentagon.org
COMMENT=	A simple tool for comparing an image to a burned disc

USES=		gmake

CFLAGS+=	-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

PLIST_FILES=	bin/dvdimagecmp

do-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} -o dvdimagecmp dvdimagecmp.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvdimagecmp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
