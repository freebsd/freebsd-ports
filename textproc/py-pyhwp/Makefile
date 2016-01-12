# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyhwp
PORTVERSION=	0.1b8
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	HWP Document Format v5 parser & processor

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}wheel>0:${PORTSDIR}/devel/py-wheel \
		${PYTHON_PKGNAMEPREFIX}olefile>=0.40:${PORTSDIR}/devel/py-olefile \
		${PYTHON_PKGNAMEPREFIX}hypua2jamo>0:${PORTSDIR}/textproc/py-hypua2jamo \
		${PYTHON_PKGNAMEPREFIX}docopt>0:${PORTSDIR}/devel/py-docopt
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
