# New ports collection makefile for:	fusefs-unionfs
# Date created:		2006-07-16
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	unionfs
PORTVERSION=	0.24
CATEGORIES=	sysutils
MASTER_SITES=	http://podgorny.cz/unionfs-fuse/releases/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	unionfs-fuse-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	FUSE based implementation of the well-known unionfs

PLIST_FILES=	bin/unionfs

USE_FUSE=	yes
USE_BZIP2=	yes

do-build:
	(cd ${WRKSRC}/src && \
	 ${CC} ${CFLAGS} -I${LOCALBASE}/include/fuse \
	 -D_FILE_OFFSET_BITS=64 -DFUSE_USE_VERSION=26 -U_POSIX_SYNCHRONIZED_IO \
	 -o unionfs *.c -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lfuse -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/unionfs ${PREFIX}/bin

.include <bsd.port.mk>
