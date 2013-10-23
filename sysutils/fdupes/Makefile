# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fdupes
PORTVERSION=	1.51
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fdupes is a program for identifying or deleting duplicate files

LICENSE=	MIT

PLIST_FILES=	bin/fdupes man/man1/fdupes.1.gz

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/md5/md5.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
