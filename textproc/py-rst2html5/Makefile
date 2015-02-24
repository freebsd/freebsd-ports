# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	rst2html5
PORTVERSION=	1.5
CATEGORIES=	textproc python
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Produces HTML5 documents from reStructuredText sources

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.7:${PORTSDIR}/textproc/py-genshi \
	${PYTHON_PKGNAMEPREFIX}pygments>=2.0:${PORTSDIR}/textproc/py-pygments \
	${PYTHON_PKGNAMEPREFIX}docutils>=0.12:${PORTSDIR}/textproc/py-docutils

USES=	python
USE_PYTHON=	distutils autoplist

BB_ACCOUNT=	andre_felipe_dias
BB_PROJECT=	${PORTNAME}
BB_COMMIT=	ab882b53331c

WRKSRC=	${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

.include <bsd.port.mk>
