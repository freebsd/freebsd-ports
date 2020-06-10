# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpaste
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Django based pastebin for text and code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=1.11:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-csp>=3.3:www/py-django-csp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-staticinline>=1.0:www/py-django-staticinline@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsx-lexer=0.0.7:textproc/py-jsx-lexer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}misaka>=2.1.0:textproc/py-misaka@${PY_FLAVOR}

USES=		python:3.4+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
