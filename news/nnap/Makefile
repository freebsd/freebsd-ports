# ex:ts=8
# Ports collection makefile for:  nnap
# Date created:                          Sun May 26, 2002
# Whom:                                  Lasse L. Johnsen (lasse@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	nnap
PORTVERSION=	1.0
CATEGORIES=	news
MASTER_SITES=	http://www.freebsdcluster.org/~lasse/software/
DISTNAME=	nnap
EXTRACT_SUFX=	.c

MAINTAINER=	lasse@freebsdcluster.org
COMMENT=	Nnap is a lightweight NNTP authentication proxy

NO_WRKSUBDIR=	yes
PLIST_FILES=	sbin/nnap

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${DISTNAME} ${DISTNAME}.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
