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
MASTER_SITES=	# part of port
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	obrien@FreeBSD.org

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
