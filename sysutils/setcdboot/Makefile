# ex:ts=8
# Ports collection makefile for:  setcdboot
# Version required:     	  1.0
# Date created:			  Mon Jan 17, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	setcdboot
PKGNAME=	setcdboot-1.0
CATEGORIES=	sysutils
MASTER_SITES=	'part of port'
EXTRACT_SUFX=	.c

MAINTAINER=     obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
DISTDIR=	${FILESDIR}

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
