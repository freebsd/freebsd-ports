# New ports collection makefile for:  jargon
# Date created: 	11 July 1998
# Whom:			moeding
#
# $FreeBSD$
#

PORTNAME=	jargon
PORTVERSION=	4.4.5
CATEGORIES=	misc
MASTER_SITES=	http://www.catb.org/~esr/jargon/

MAINTAINER=	sf@FreeBSD.org
COMMENT=	The famous jargon file

NO_BUILD=	yes
USE_REINPLACE=	yes

DATADIR=	${PREFIX}/share/jargon

post-extract:
	(cd ${WRKSRC}; ${RM} -rf html/graphics/.xvpics graphics/.xvpics)

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}; pax -rw . ${DATADIR})
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

.include <bsd.port.mk>
