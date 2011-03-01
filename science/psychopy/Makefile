# Ports collection makefile for:	psychopy
# Date created:			27 Feb, 2009
# Whom:				wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	psychopy
PORTVERSION=	1.63.03
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	PsychoPy-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Psychophysics toolkit for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.1.0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:${PORTSDIR}/graphics/py-pyglet \
		${PYTHON_PKGNAMEPREFIX}wxPython>=2.8.7.1:${PORTSDIR}/x11-toolkits/py-wxPython28 \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_ZIP=		yes
USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	PsychoPy

.include <bsd.port.mk>
