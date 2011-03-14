# New ports collection makefile for:	py-obspy.gse2
# Date created:				Jan 26, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	obspy.gse2
PORTVERSION=	0.4.7
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read & write seismograms, Format GSE2

BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}obspy.core>=0.4.6:${PORTSDIR}/science/py-obspy.core

USE_ZIP=		yes
USE_PYTHON=		yes
PYEASYINSTALL_ARCHDEP=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
