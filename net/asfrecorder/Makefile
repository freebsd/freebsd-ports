# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	asfrecorder
PORTVERSION=	1.1.20010307
CATEGORIES=	net audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1
DISTNAME=	ASFRecorder

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Tool for downloading streaming media from the Internet

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-10

USE_ZIP=	yes

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/source/asfrecorder.c -o ${WRKSRC}/asfrecorder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asfrecorder ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/asfrecorder
	${INSTALL_DATA} ${WRKSRC}/README.TXT \
		${STAGEDIR}${PREFIX}/share/doc/asfrecorder

.include <bsd.port.mk>
