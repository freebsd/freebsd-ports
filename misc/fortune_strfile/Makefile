# Created by: marino@FreeBSD.org
# $FreeBSD$

PORTNAME=	fortune_strfile
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Duplicate of strfile(8)

PROGRAM=	fortune_strfile
PLIST_FILES=	bin/${PROGRAM}

DEPRECATED=	unmaintained and duplicated from base
EXPIRATION_DATE=	2016-10-14

do-build:
	${MKDIR} ${WRKSRC}
	${CC} ${CFLAGS} -o ${WRKSRC}/${PROGRAM} ${FILESDIR}/strfile.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
