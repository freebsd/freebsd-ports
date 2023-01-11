PORTNAME=	creole
DISTVERSION=	1.4.10
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	count@211.ru
COMMENT=	Markup converter in pure Python
WWW=		https://pypi.org/project/python-creole/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/docutils/__init__.py:textproc/py-docutils@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--install-data ${DATADIR}

.include <bsd.port.post.mk>
