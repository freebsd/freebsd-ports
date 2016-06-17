# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rekall-core
DISTVERSION=	1.5.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	CORE component of the Rekall framework

LICENSE=	GPLv2

RUN_DEPENDS=	cabextract:archivers/cabextract \
		${PYTHON_PKGNAMEPREFIX}PyAFF4>=0.23:security/py-pyaff4 \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}acora>=2.0:textproc/py-acora \
		${PYTHON_PKGNAMEPREFIX}arrow>=0.7.0:devel/py-arrow \
		${PYTHON_PKGNAMEPREFIX}efilter>=1.2,1:devel/py-efilter \
		${PYTHON_PKGNAMEPREFIX}intervaltree>=2.1.0:devel/py-intervaltree \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6.1:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pyelftools>=0.23:devel/py-pyelftools \
		${PYTHON_PKGNAMEPREFIX}pytz>=2016.4,1:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}capstone>=3.0.4:devel/py-capstone \
		${PYTHON_PKGNAMEPREFIX}yara>=3.4.0:security/py-yara \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=1.4.4:devel/py-sortedcontainers \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.4.2:devel/py-dateutil

NO_ARCH=	yes
USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
