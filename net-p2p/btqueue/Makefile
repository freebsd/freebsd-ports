# New ports collection makefile for:	BTQueue
# Date created:				04 Jun 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	btqueue
PORTVERSION=	0.0.14
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	BTQueue-${PORTVERSION}

MAINTAINER=	sw@gegenunendlich.de
COMMENT=	Alternative BitTorrent client with queuing functionality

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_bsddb.so:${PORTSDIR}/databases/py-bsddb

CONFLICTS=	py??-*[Bb]it[Tt]ornado* py??-*[Bb]it[Tt]orrent*
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
