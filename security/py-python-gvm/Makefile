PORTNAME=	python-gvm
DISTVERSION=	22.9.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Greenbone Vulnerability Management Python API library
WWW=		https://github.com/greenbone/python-gvm

LICENSE=	GPLv3+

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -i "" -e 's|/run/gvmd/|/var/run/gvmd/|g' \
		${WRKSRC}/gvm/connections.py

.include <bsd.port.mk>
