PORTNAME=	progressbar
PORTVERSION=	2.5
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Text progressbar library for python
WWW=		https://github.com/niltonvolpato/python-progressbar

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.txt

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}progressbar231

.include <bsd.port.mk>
