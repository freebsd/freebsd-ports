# ex:ts=8
# Ports collection makefile for:  setcdboot
# Date created:			  Mon Jan 17, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	setcdboot
PORTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes

do-fetch:

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${FILESDIR}/setcdboot.c ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o setcdboot setcdboot.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setcdboot ${PREFIX}/bin

.include <bsd.port.mk>
