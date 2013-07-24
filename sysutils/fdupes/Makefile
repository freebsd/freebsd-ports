# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fdupes
DISTVERSION=	1.50-PR2
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Fdupes is a program for identifying or deleting duplicate files

LICENSE=	MIT

MAN1=		fdupes.1
PLIST_FILES=	bin/fdupes

CFLAGS+=	-DVERSION=\"${PORTVERSION}\"

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/md5/md5.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
