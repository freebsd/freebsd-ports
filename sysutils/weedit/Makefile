# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	weedit
PORTVERSION=	2.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://adm1n.cjb.net/cw/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	File duplicate scanner with database support

LICENSE=	GPLv2

USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
SRCF=		crc32 dlink weedit md5

PLIST_FILES=	bin/weedit bin/weeditreaddb

do-build:
.for f in ${SRCF}
	${CC} ${CFLAGS} -c ${WRKSRC}/${f}.c -o ${WRKSRC}/${f}.o
.endfor
	${CC} ${CFLAGS} ${WRKSRC}/utils/readdb.c -o ${WRKSRC}/weeditreaddb
	${CC} ${LDFLAGS} -o ${WRKSRC}/${PORTNAME} \
		${SRCF:C/(.*)/${WRKSRC}\/\1.o/}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/weeditreaddb ${PREFIX}/bin

.include <bsd.port.mk>
