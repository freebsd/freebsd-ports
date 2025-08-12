PORTNAME=	molequeue
DISTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	https://github.com/openchemistry/molequeue/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for MolEqueue, task management framework
WWW=		https://www.openchemistry.org/projects/molequeue

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang python
USE_PYTHON=	flavors

NO_ARCH=	yes
WRKSRC_SUBDIR=	python

.include <bsd.port.mk>
