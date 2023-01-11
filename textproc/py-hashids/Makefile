PORTNAME=	hashids
PORTVERSION=	1.3.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Implement the hashids algorithm in python
WWW=		https://github.com/davidaurelio/hashids-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
