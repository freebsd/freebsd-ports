# Created by: rene
# $FreeBSD$

PORTNAME=	biosfont-demos
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	LOCAL/rene

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Demos for the biosfont kernel module

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/biosfont.h:sysutils/biosfont
RUN_DEPENDS=	/boot/modules/biosfont.ko:sysutils/biosfont

PLIST_FILES=	bin/show_char bin/showdati

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/showchar.c -o ${WRKSRC}/show_char -I${LOCALBASE}/include
	${CC} ${CFLAGS} ${WRKSRC}/showdati.c -o ${WRKSRC}/showdati -I${LOCALBASE}/include -lcurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/show_char ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/showdati ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
