# New ports collection makefile for:   samplicator
# Date created:        1 June 2001
# Whom:                Michael Lyngbol <lyngbol@wheel.dk>
#
# $FreeBSD$
#

PORTNAME=	samplicator
PORTVERSION=	1.3.2
CATEGORIES=	net
MASTER_SITES=	http://www.switch.ch/tf-tant/floma/sw/samplicator/

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	Receives UDP datagrams and redistributes them to a set of receivers

GNU_CONFIGURE=	yes

post-install:
	${MKDIR} ${DOCSDIR}
.for file in NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor

.include <bsd.port.mk>
