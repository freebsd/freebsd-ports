# Ports collection makefile for:  asfrecorder
# Date created:			  Oct 6 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	asfrecorder
PORTVERSION=	1.1.20010307
CATEGORIES=	net audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1
DISTNAME=	ASFRecorder

MAINTAINER= 	ports@FreeBSD.org
COMMENT=	Tool for downloading streaming media from the Internet

USE_ZIP=	yes

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/source/asfrecorder.c -o ${WRKSRC}/asfrecorder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asfrecorder ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/asfrecorder
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${PREFIX}/share/doc/asfrecorder
.endif

.include <bsd.port.mk>
