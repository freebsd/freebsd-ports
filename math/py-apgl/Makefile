# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	apgl
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Fast python graph library with some machine learning features

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0.7.0:${PORTSDIR}/science/py-scipy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
