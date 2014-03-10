# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	physcalc
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.lightlink.com/pub/vulcan/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible calculator that behaves much like units(1)

EXTRACT_BEFORE_ARGS=	-aq
EXTRACT_AFTER_ARGS=	-x physcalc -d ${WRKDIR}

NO_WRKSUBDIR=	yes
USES=		zip

DEFS=		-DSHAREDIR="\"${PREFIX}/share/physcalc/\""
SRCS=		physconv.c physmain.c physmlib.c physnode.c physoper.c \
		physsolv.c
CFLAGS+=	-Wno-return-type

pre-build:
	${REINPLACE_CMD} -e "s@void main@int main@g" ${WRKSRC}/physmain.c

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} ${DEFS} ${SRCS} -lm -o physcalc)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/physcalc ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/physcalc
	${INSTALL_DATA} ${WRKSRC}/*.phy ${STAGEDIR}${PREFIX}/share/physcalc

.include <bsd.port.mk>
