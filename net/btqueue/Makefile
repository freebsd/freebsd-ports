# New ports collection makefile for:	BTQueue
# Date created:				04 Jun 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	btqueue
PORTVERSION=	0.0.18
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

DATADIR=	${PREFIX}/share/BTQueue
DOCSDIR=	${PREFIX}/share/doc/BTQueue

OPTIONS=	PYXML "Add dependency on PyXML (needed for crawler only)" on

.include <bsd.port.pre.mk>

.if defined(WITH_PYXML)
RUN_DEPENDS+=	${PYXML}
.endif

.include <bsd.port.post.mk>
