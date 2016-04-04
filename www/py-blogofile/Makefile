# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blogofile
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/B/Blogofile
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Static website compiler and blog engine

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}textile>0:www/py-textile \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
