PORTNAME=	django-multiselectfield
PORTVERSION=	0.1.12
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Django multiple select field
WWW=		https://github.com/goinnn/django-multiselectfield

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LGPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=2.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*${PORTNAME}

NO_ARCH=	yes

.include <bsd.port.mk>
