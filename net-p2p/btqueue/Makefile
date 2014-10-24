# Created by: Stefan Walter <sw@gegenunendlich.de>
# $FreeBSD$

PORTNAME=	btqueue
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF
DISTNAME=	BTQueue-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alternative BitTorrent client with queuing functionality

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bsddb>0:${PORTSDIR}/databases/py-bsddb

CONFLICTS=	py??-*[Bb]it[Tt]ornado* py??-*[Bb]it[Tt]orrent*
USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	BTQueue

DATADIR=	${PREFIX}/share/BTQueue
DOCSDIR=	${PREFIX}/share/doc/BTQueue

OPTIONS_DEFINE=	PYXML DOCS
OPTIONS_DEFAULT=PYXML
PYXML_DESC=	Add dependency on PyXML (needed for crawler only)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYXML}
RUN_DEPENDS+=	${PYXML}
.endif

.include <bsd.port.mk>
