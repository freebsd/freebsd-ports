# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	xorsearch
DISTVERSION=	1_2_0
PORTREVISION=	1
CATEGORIES=	security textproc
MASTER_SITES=	http://www.didierstevens.com/files/software/
DISTNAME=	XORSearch_V${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Search for a given string in an XOR or ROL encoded binary file

LICENSE=	PD

USES=		dos2unix zip
DOS2UNIX_GLOB=	*.c
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/xorsearch

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/XORSearch ${WRKSRC}/XORSearch.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/XORSearch ${STAGEDIR}${PREFIX}/bin/xorsearch

.include <bsd.port.mk>
