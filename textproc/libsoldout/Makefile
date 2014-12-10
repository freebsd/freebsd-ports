# $FreeBSD$

PORTNAME=	libsoldout
DISTVERSION=	1.3
CATEGORIES=	textproc devel
MASTER_SITES=	http://instinctive.eu/code/

MAINTAINER=	natbsd@instinctive.eu
COMMENT=	Flexible C library for markdown

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKEFILE=	BSDmakefile
USE_LDCONFIG=	yes
USES=	tar:bzip2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libsoldout.so.1 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/mkd2html ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkd2latex ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkd2man ${STAGEDIR}${PREFIX}/bin
	cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libsoldout.so.1 libsoldout.so
	${MKDIR} ${STAGEDIR}${PREFIX}/include/soldout
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/soldout

.include <bsd.port.mk>
