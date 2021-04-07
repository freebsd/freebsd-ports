PORTNAME=	pubs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Your bibliography on the command line

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bibtexparser>=1.0:textproc/py-bibtexparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
