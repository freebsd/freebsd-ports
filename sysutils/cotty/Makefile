# New ports collection makefile for:	cotty
# Date created:		26 January 2001
# Whom:			Oliver Breuninger <ob@breuninger.org>
#
# $FreeBSD$
#

PORTNAME=	cotty
PORTVERSION=	0.4c
CATEGORIES=	sysutils
MASTER_SITES=	http://fare.tunes.org/files/fwprc/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	ob@breuninger.org

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${DISTNAME}.c

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/cotty ${WRKSRC}/${DISTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cotty ${PREFIX}/bin

.include <bsd.port.mk>
