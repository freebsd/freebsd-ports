# New ports collection makefile for:	fusefs-gunzip
# Date created:				2008-06-16
# Whom:					Evgeny Zhirnov <jirnov@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fuse.gunzip
PORTVERSION=	20070320
CATEGORIES=	sysutils
MASTER_SITES=	http://fuse.gunzip.silverice.org/files/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Fuse.gunzip provides transparent decompression of gzip compressed files

WRKSRC=		${WRKDIR}/fuse.gunzip
USE_FUSE=	yes

PLIST_FILES=	bin/fuse.gunzip

NO_INSTALL_MANPAGES=	yes

do-build:
	(cd ${WRKSRC} && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/fuse \
	-D_FILE_OFFSET_BITS=64 \
	-o fuse.gunzip fuse.gunzip.c -L${LOCALBASE}/lib ${PTHREAD_LIBS} \
	-lulockmgr -lz -lfuse -liconv -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fuse.gunzip ${PREFIX}/bin

.include <bsd.port.mk>
