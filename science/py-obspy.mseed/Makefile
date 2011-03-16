# New ports collection makefile for:	py-obspy.mseed
# Date created:				Jan 26, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	obspy.mseed
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read & write seismograms, Format MiniSeed

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}obspy-core>=0.4.6:${PORTSDIR}/science/py-obspy-core
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}obspy-core>=0.4.6:${PORTSDIR}/science/py-obspy-core

USE_ZIP=		yes
USE_PYTHON=		yes
PYEASYINSTALL_ARCHDEP=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
