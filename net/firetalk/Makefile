# New ports collection makefile for:   firetalk
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	firetalk
PORTVERSION=	0.0.11
CATEGORIES=	net
MASTER_SITES=	http://www.penguinhosting.net/~ian/firetalk/

MAINTAINER=	greid@ukug.uk.freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}

INSTALLS_SHLIB=	yes

FTHEADERS=	firetalk-int.h icqv5.h toc.h firetalk.h irc.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/firetalk ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/firetalk
.for H in ${FTHEADERS}
	${INSTALL_DATA} ${WRKSRC}/$H ${PREFIX}/include/firetalk
.endfor
	${INSTALL_DATA} ${WRKSRC}/libfiretalk.a ${PREFIX}/lib

.include <bsd.port.mk>
