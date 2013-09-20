# Created by: Kuan-Chung Chiu <buganini@gmail.com>
# $FreeBSD$

PORTNAME=	yamdi
PORTVERSION=	1.9
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	Metadata injector for FLV files

LICENSE=	BSD

PLIST_FILES=	bin/yamdi

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} yamdi.c -o yamdi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yamdi ${PREFIX}/bin

.include <bsd.port.mk>
