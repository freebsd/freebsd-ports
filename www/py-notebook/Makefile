# $FreeBSD$

PORTNAME=	notebook
PORTVERSION=	5.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web-based notebook environment for interactive computing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=5.2.0:devel/py-jupyter_client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=4.4.0:devel/py-jupyter_core@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=0:devel/py-nbconvert@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}send2trash>=0:deskutils/py-send2trash@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}terminado>=0.8.1:net/py-terminado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4:www/py-tornado@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2.1:devel/py-traitlets@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
