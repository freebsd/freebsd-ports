# ex:ts=8
# Ports collection Makefile for:	avinfo
# Date created:			Feb 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	avinfo
PORTVERSION=	0.7.3
CATEGORIES=	multimedia
MASTER_SITES=	http://anime.org.ru/soft/avinfo/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility for displaying AVI header information

WRKSRC=		${WRKDIR}/src

USE_ZIP=	yes
USE_REINPLACE=	yes

post-patch:
	@(cd ${WRKSRC} && ${CP} messages.c temp ; \
		${CAT} temp | col -b > messages.c)

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o avinfo avinfo.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/avinfo ${PREFIX}/bin

.include <bsd.port.mk>
