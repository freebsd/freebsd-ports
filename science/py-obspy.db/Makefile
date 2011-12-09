# New ports collection makefile for:	py-obspy.db
# Date created:				Dec 9, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	obspy.db
PORTVERSION=	0.5.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A seismic waveform indexer and database for ObsPy

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}obspy-core>=0.4.6:${PORTSDIR}/science/py-obspy-core

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
