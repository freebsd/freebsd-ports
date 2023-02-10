PORTNAME=	sphinx-design
PORTVERSION=	0.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_design-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sphinx extension for designing beautiful, view size responsive web components
WWW=		https://github.com/executablebooks/sphinx-design

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=4,1<6,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

.include <bsd.port.mk>
