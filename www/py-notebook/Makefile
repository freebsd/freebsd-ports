# $FreeBSD$

PORTNAME=	notebook
PORTVERSION=	4.3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web-based notebook environment for interactive computing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}terminado>=0.3.3:net/py-terminado \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets \
		${PYTHON_PKGNAMEPREFIX}tornado>=4:www/py-tornado \
		${PYTHON_PKGNAMEPREFIX}nbformat>=0:devel/py-nbformat \
		${PYTHON_PKGNAMEPREFIX}nbconvert>=0:devel/py-nbconvert \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=0:devel/py-jupyter_core \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=0:devel/py-ipykernel

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
