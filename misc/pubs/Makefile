PORTNAME=	pubs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	misc python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Your bibliography on the command line
WWW=		https://github.com/pubs/pubs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bibtexparser>=1.0:textproc/py-bibtexparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

PORTSCOUT=	skipv:show_and_search

.include <bsd.port.mk>
