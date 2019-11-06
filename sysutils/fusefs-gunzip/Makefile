# Created by: Evgeny Zhirnov <jirnov@gmail.com>
# $FreeBSD$

PORTNAME=	fuse.gunzip
PORTVERSION=	20070320
CATEGORIES=	sysutils
MASTER_SITES=	http://fuse.gunzip.silverice.org/files/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Fuse.gunzip provides transparent decompression of gzip compressed files

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/fuse.gunzip
USES=		fuse

PLIST_FILES=	bin/fuse.gunzip

do-build:
	(cd ${WRKSRC} && \
	${CC} ${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/fuse \
	-D_FILE_OFFSET_BITS=64 \
	-o fuse.gunzip fuse.gunzip.c -L${LOCALBASE}/lib \
	-lulockmgr -lz -lfuse ${ICONV_LIB} -lm)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fuse.gunzip ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
