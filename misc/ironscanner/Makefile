# $FreeBSD$

PORTNAME=	ironscanner
DISTVERSION=	1.1.0.20180715
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collect as much information as possible on image scanners

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyinsane2>0:graphics/py-pyinsane2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		gmake python:3.4+
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/OpenPaperwork
GL_COMMIT=	b2d3a2f04d407a3cfb54d537082a872e7b2bc093
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
