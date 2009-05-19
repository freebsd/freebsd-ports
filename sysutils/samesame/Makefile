# New ports collection makefile for:	samesame
# Date created:		14 April 2009
# Whom:			Alex de Kruijff
#
# $FreeBSD$

PORTNAME=	samesame
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.akruijff.dds.nl/samesame/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	samesame@akruijff.dds.nl
COMMENT=	Find identical files and optionally link them together

CONFLICTS=	samefile-[0-9]*

MAN1=	samearchive.1 samearchive-lite.1 samefile.1 samelink.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/samearchive \
		bin/samearchive-lite \
		bin/samefile \
		bin/samelink

USE_BZIP2=	yes

OPTIONS=	DEBUG "Enables debugging support" Off \
		DISK_STORAGE "Allow temporarily storage paths on disk" On \
		LOGIC "Determine results by using logic when posible" On

.if defined(WITH_DEBUG)
CFLAGS+=	-DDEBUG
.endif

.if defined(WITH_DISK_STORAGE)
CFLAGS+=	-DWITH_DISK_STORAGE
.endif

.if defined(WITH_LOGIC)
CFLAGS+=	-DWITH_LOGIC
.endif

CFLAGS+=	-DWITH_MMAP
CFLAGS+=	-D'TEMP_STORAGE_DIR=\"/tmp\"'
CFLAGS+=	-DPATH_INIT=256
CFLAGS+=	-DSTATIC_CACHE_CAPACITY=8192

post-patch:
	@${REINPLACE_CMD} -e '/^install/s|test-samefile||g' \
	-e '/^install/s|test-samelink||g' \
	-e '/^install/s|test-samearchive-lite||g' \
	-e '/^install/s|test-samearchive||g' ${WRKSRC}/Makefile

post-install:
	${CHMOD} 770 ${WRKSRC}/test*
	${STRIP_CMD} ${PREFIX}/bin/samefile
	${STRIP_CMD} ${PREFIX}/bin/samelink
	${STRIP_CMD} ${PREFIX}/bin/samearchive
	${STRIP_CMD} ${PREFIX}/bin/samearchive-lite

.include <bsd.port.mk>
