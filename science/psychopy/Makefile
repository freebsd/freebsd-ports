# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	psychopy
PORTVERSION=	1.81.02
CATEGORIES=	science python
MASTER_SITES=	SF/psychpy/PsychoPy
DISTNAME=	PsychoPy-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Psychophysics toolkit for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.1.0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}pillow>0:${PORTSDIR}/graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:${PORTSDIR}/graphics/py-pyglet \
		${PYTHON_PKGNAMEPREFIX}wxPython28>=2.8.7.1:${PORTSDIR}/x11-toolkits/py-wxPython28 \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=			python zip
USE_PYTHON=		autoplist distutils

# needed to avoid polluting /root, since psychopy
# tries to create some configuration files on import
# through distutils
MAKE_ENV+=		HOME=/dev/null

.include <bsd.port.mk>
