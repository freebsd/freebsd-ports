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
COMMENT=	Mark a file bootable within a DEC Alpha ISO-9660 image

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/setcdboot

do-fetch:

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${FILESDIR}/setcdboot.c ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o setcdboot setcdboot.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/setcdboot ${PREFIX}/bin

.include <bsd.port.mk>
