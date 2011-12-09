# New ports collection makefile for:	py-obspy.wav
# Date created:				March 21, 2011
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	obspy.wav
PORTVERSION=	0.5.0
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	WAV(audio) read and write support for ObsPy

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}obspy-core>=0.4.6:${PORTSDIR}/science/py-obspy-core
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}obspy-core>=0.4.6:${PORTSDIR}/science/py-obspy-core

USE_ZIP=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
