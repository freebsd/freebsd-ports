# New ports collection makefile for:	BTQueue
# Date created:				04 Jun 2004
# Whom:					Stefan Walter <sw@gegenunendlich.de>
#
# $FreeBSD$
#

PORTNAME=	btqueue
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	net-p2p
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

# Enable workaround for bad libc in FreeBSD 4.x
.if ${OSVERSION} < 500000
EXTRA_PATCHES=	${FILESDIR}/FBSD4-patch-BitTorrent_defaultargs.py
.endif

.if !defined(WITHOUT_PYXML)
RUN_DEPENDS+=	${PYXML}
.endif

.include <bsd.port.post.mk>
