# New ports collection makefile for:	bnbt
# Date created:				Jan 31 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	bnbt
PORTVERSION=	7.5b2
CATEGORIES=	net
MASTER_SITES=	http://bnbt.go-dedicated.com/
DISTNAME=	bnbt75b-2

MAINTAINER=	flz@xbsd.org
COMMENT=	A C++ BitTorrent Tracker

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -w|${CFLAGS}| ; \
		s|LFLAGS = -pthread|LFLAGS = ${PTHREAD_LIBS}| ; \
		s|CFLAGS = -pthread|CFLAGS = ${PTHREAD_CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnbt ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for i in footer.html header.html lesser.txt readme.txt users.txt
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/$i ${DATADIR}
.endfor

.include <bsd.port.mk>
