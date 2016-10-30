# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blogofile
PORTVERSION=	0.8.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP/source/B/Blogofile
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Blogofile-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Static website compiler and blog engine

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.19:textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}textile>0:www/py-textile \
		${PYTHON_PKGNAMEPREFIX}unidecode>=0:converters/py-unidecode \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
