# New ports collection makefile for:	cotty
# Date created:		26 January 2001
# Whom:			Oliver Breuninger <ob@breuninger.org>
#
# $FreeBSD$
#

PORTNAME=	cotty
PORTVERSION=	0.4c
CATEGORIES=	sysutils
MASTER_SITES=	http://www.breuninger.org/files/distfiles/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	ob@breuninger.org
COMMENT=	Simple command-line pseudo terminal manager

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/cotty
EXTRACT_CMD=	${GZCAT}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	> ${WRKSRC}/${DISTNAME}.c

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/cotty ${WRKSRC}/${DISTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cotty ${PREFIX}/bin

.include <bsd.port.mk>
