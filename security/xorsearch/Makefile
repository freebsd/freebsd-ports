# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	xorsearch
PORTVERSION=	1.2.0
CATEGORIES=	security textproc
MASTER_SITES=	http://www.didierstevens.com/files/software/
DISTNAME=	XORSearch_V1_2_0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search for a given string in an XOR or ROL encoded binary file

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.c
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/xorsearch

do-build:
	${CC} -o ${WRKSRC}/XORSearch ${WRKSRC}/XORSearch.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/XORSearch \
		${STAGEDIR}${PREFIX}/bin/xorsearch

.include <bsd.port.mk>
