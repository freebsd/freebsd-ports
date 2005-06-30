# ex:ts=8
# Ports collection makefile for:	shc
# Date created:		Feb 14, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shc
PORTVERSION=	3.8.3
CATEGORIES=	misc
MASTER_SITES=	http://www.datsi.fi.upm.es/~frosal/sources/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A shell script "encoder"

MAN1=		shc.1
PLIST_FILES=	bin/shc

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o shc shc.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/shc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/shc.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
