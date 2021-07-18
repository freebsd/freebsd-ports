# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	errbot
PORTVERSION=	6.1.8
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Chatbot designed to be simple to extend with plugins

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ansi>=0:devel/py-ansi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorlog>=0:devel/py-colorlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemonize>=0:devel/py-daemonize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepmerge>=0.1.0:devel/py-deepmerge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.19.16:devel/dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.0.2:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=0:www/py-WebTest@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
