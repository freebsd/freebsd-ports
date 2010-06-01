# New ports collection makefile for:    yamdi
# Date created:                         9 July 2007
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	yamdi
PORTVERSION=	1.5
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	buganini@gmail.com
COMMENT=	A metadata injector for FLV files

PLIST_FILES=	bin/yamdi

do-build:
	cd ${WRKSRC} \
	&& ${CC} ${CFLAGS} yamdi.c -o yamdi

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yamdi ${PREFIX}/bin

.include <bsd.port.mk>
