# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	blogofile
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/B/Blogofile
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A static website compiler and blog engine

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup32>0:${PORTSDIR}/www/py-beautifulsoup32 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}textile>0:${PORTSDIR}/www/py-textile \
		${PYTHON_PKGNAMEPREFIX}markdown>0:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}pygments>0:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}docutils>0:${PORTSDIR}/textproc/py-docutils

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Blogofile

NO_STAGE=	yes
.include <bsd.port.mk>
