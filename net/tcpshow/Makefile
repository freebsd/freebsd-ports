# ex:ts=8
# Ports collection makefile for:  tcpshow
# Date created:			  Tue Nov 04, 1997
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	tcpshow-1.74
CATEGORIES=	net security
MASTER_SITES=	http://people.FreeBSD.org/~obrien/Distfiles/
#		http://www.cs.berkeley.edu/~daw/mike/
DISTFILES=	tcpshow.c tcpshow.1

MAINTAINER=	obrien@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		tcpshow.1

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/tcpshow.c ${WRKDIR}
	@${CP} ${DISTDIR}/tcpshow.1 ${WRKDIR}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o tcpshow tcpshow.c)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpshow ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tcpshow.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
