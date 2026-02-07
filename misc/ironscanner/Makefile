PORTNAME=	ironscanner
DISTVERSION=	1.1.0.20180828
PORTREVISION=	2
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collect as much information as possible on image scanners
WWW=		https://openpaper.work/en-us/scanner_db/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pyinsane2>0:graphics/py-pyinsane2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org/World
GL_ACCOUNT=	OpenPaperwork
GL_TAGNAME=	e73528c5602088eb75f99b78a498dec622b5c97e
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
