# ex:ts=8
# Ports collection makefile for:  vnTeX
# Date created:		Monday, Dec 9, 1996
# Whom:			David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	vnroff
PORTVERSION=	2.1
CATEGORIES=	vietnamese print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTFILES=	vnroff.c.Z vnroff.1.Z
DISTNAME=	${PORTNAME}-2.0

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Converts Vietnamese VIQR text into troff format

NO_WRKSUBDIR=	yes
MAN1=		vnroff.1

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} && ${GZCAT} ${DISTDIR}/vnroff.c.Z  \
		| ${SED} -e '1,/-cut here-/d'    \
		> vnroff.c)
	@(cd ${WRKDIR} && ${GZCAT} ${DISTDIR}/vnroff.1.Z  \
		| ${SED} -e '1,/Status:/d' -e '//,//d'  \
		| ${SED} -e '1,1d'  \
		> vnroff.1)

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o vnroff vnroff.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnroff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vnroff.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
