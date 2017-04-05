# $FreeBSD$

PORTNAME=	notebook
PORTVERSION=	5.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web-based notebook environment for interactive computing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=0:devel/py-jupyter_client \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=0:devel/py-jupyter_core \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=0:devel/py-nbconvert \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat \
		${PYTHON_PKGNAMEPREFIX}terminado>=0.3.3:net/py-terminado \
		${PYTHON_PKGNAMEPREFIX}tornado>=4:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}traitlets>=4.2.1:devel/py-traitlets

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
