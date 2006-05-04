# New ports collection makefile for:	dvdimagecmp
# Date created:				11 October 2005
# Whom:					Tim Welch <ports@thepentagon.org>
#
# $FreeBSD$
#

PORTNAME=	dvdimagecmp
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/video
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@thepentagon.org
COMMENT=	A simple tool for comparing an image to a burned disc

USE_GMAKE=	yes
CFLAGS+=	-D_LARGEFILE_SOURCE -D_FILE_OFFSET_BITS=64

PLIST_FILES=	bin/dvdimagecmp

do-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} -o dvdimagecmp dvdimagecmp.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dvdimagecmp ${PREFIX}/bin

.include <bsd.port.mk>
