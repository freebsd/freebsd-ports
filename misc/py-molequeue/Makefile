# $FreeBSD$

PORTNAME=	molequeue
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	https://github.com/openchemistry/molequeue/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for MolEqueue, task management framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}

USES=		cmake:outsource compiler:c++11-lang python
USE_PYTHON=	flavors

WRKSRC_SUBDIR=	python

.include <bsd.port.mk>
