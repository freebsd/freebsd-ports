# New ports collection makefile for:	py-obspy.signal
# Date created:				Jan 26, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	obspy.signal
PORTVERSION=	0.4.7
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python signal processing routines for seismology

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}obspy-core>=0.4.6:${PORTSDIR}/science/py-obspy-core
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ZIP=		yes
USE_PYTHON=		yes
PYEASYINSTALL_ARCHDEP=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
