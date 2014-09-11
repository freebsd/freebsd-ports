# Created by: wenheping@gmail.com
# $FreeBSD$

PORTNAME=	psychopy
PORTVERSION=	1.77.00
PORTREVISION=	4
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	PsychoPy-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Psychophysics toolkit for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.1.0:${PORTSDIR}/math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.6.0:${PORTSDIR}/science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pyglet>=1.1.2:${PORTSDIR}/graphics/py-pyglet \
		${PYTHON_PKGNAMEPREFIX}wxPython28>=2.8.7.1:${PORTSDIR}/x11-toolkits/py-wxPython28 \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.90.1:${PORTSDIR}/math/py-matplotlib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=			zip
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

# needed to avoid polluting /root, since psychopy
# tries to create some configuration files on import
# through distutils
MAKE_ENV+=		HOME=/dev/null

.include <bsd.port.mk>
